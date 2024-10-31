<?php
/*
Plugin Name: Real Statistics
Plugin URI: http://www.sebbi.de/development/realstats
Description: This plugin aims to be a THE statistic tool for your wordpress blog. Hopefully you'll never feel the need to use anything else :-)
Version: 0.5
Author: Sebastian Herp
Author URI: http://www.sebbi.de
*/ 

/* LICENSE STUFF
Real Statistic Plugin for Wordpress 1.2
Copyright (C) 2004 Sebastian Herp

This program is free software; you can redistribute it and/or 
modify it under the terms of the GNU General Public License as 
published by the Free Software Foundation; either version 2 of the 
License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but 
WITHOUT ANY WARRANTY; without even the implied warranty of 
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
General Public License for more details.

You should have received a copy of the GNU General Public License 
along with this program; if not, write to the Free Software 
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 
USA
*/



/* SETUP/OPTIONS */
$realstats_diabled = false; // set this to "false" to start the counter
$realstats_visit_timeout = 1800; // visit timeout

$realstats_dont_include_in_referrers = array( //host in this list wont appear in any referrer-list
	get_settings('siteurl'),
	"sebbi.de",
	"feedster.com",
	"alltheweb.com",
	"suche.lycos.de",
	"comcast.net",
	"altavista.com",
	"www.technorati.com",
	"www.netcraft.com",
	"blo.gs",
	"google.",
	"yahoo.",
	"aol.",
	"search.msn.de",
	"blogg.de",
	"suche.fireball.de",
	"suche.web.de",
	"brisbane.t-online.de");
	

$table_wp_log_hits = "wp_log_hits"; // the hits-db-table
$table_wp_log_visits = "wp_log_visits"; // the visits-db-table
$table_wp_log_dns = "wp_log_dns"; // the dns-db-table
/* END SETUP/OPTIONS */


/* this is the core of the plugin
 * DO NOT change it :-)
*/
include("realstats/realstats_data.inc");

if( !$realstats_disabled && !strstr($_SERVER['PHP_SELF'], 'wp-admin/')) {  //we do not want to count the admin-clicks
	realstats_count(time(),
		mysql_escape_string($_SERVER["REMOTE_ADDR"]),
		mysql_escape_string($_SERVER["HTTP_USER_AGENT"]),
		mysql_escape_string(trim($_COOKIE['wordpressuser_'.$cookiehash])),
		mysql_escape_string(trim($_COOKIE['comment_author_'.$cookiehash])),
		mysql_escape_string($_SERVER["SCRIPT_NAME"]),
		mysql_escape_string($_SERVER["QUERY_STRING"]),
		mysql_escape_string($_SERVER["HTTP_REFERER"]));
}

/* realstats_count($timestamp, $ip, $useragent, $wordpressuser, $comment_author, $site, $querystring, $referrer)
 *
 * You might have guessed it ... yes, it counts hits :-)
*/
function realstats_count($timestamp, $ip, $useragent, $wordpressuser, $comment_author, $site, $querystring, $referrer) {
	global $wpdb, $table_wp_log_hits, $table_wp_log_visits, $realstats_visit_timeout;
	
	$rows = $wpdb->query("SELECT visits.visitID 
		FROM $table_wp_log_hits as hits INNER JOIN $table_wp_log_visits as visits ON hits.visitID = visits.visitID
		WHERE IP = INET_ATON('$ip')
		AND useragent = '$useragent'
		AND wordpressuser = '$wordpressuser'
		AND comment_author = '$comment_author'
		AND datetime > SUBDATE('".gmdate('Y-m-d H:i:s', $timestamp)."', INTERVAL $realstats_visit_timeout SECOND) 
		AND datetime <= '".gmdate('Y-m-d H:i:s', $timestamp)."'
		GROUP BY visits.visitID");
	if($rows>0) {	//do we know the visitor?
		$thisvisitID = $wpdb->get_var(); 
	}	else {
		$temparray=realstats_useragent2array($useragent);
		if($temparray["browser"]=="other") { $flags = "unknown"; }
			elseif($temparray["robot"]) { $flags = "robot"; }
			else { $flags = "browser"; }			
		$wpdb->query("INSERT INTO $table_wp_log_visits
			(IP, useragent, wordpressuser, comment_author, browser, os, flags) VALUES
			(INET_ATON('$ip'), '$useragent', '$wordpressuser', '$comment_author', '".$temparray["browser"]."', '".$temparray["os"]."', '".$flags."') ");
		$thisvisitID = $wpdb->insert_id; 
	}
	$wpdb->query("INSERT INTO $table_wp_log_hits
		(visitID, datetime, site, querystring, referrer) VALUES
		('$thisvisitID', '".gmdate('Y-m-d H:i:s', $timestamp)."', '$site', '$querystring', '$referrer') ");
}


/* realstats_url2shorturl($url, $start=0, $length=25)
 *
 * returns shorter urls
*/
function realstats_url2shorturl($url, $start=0, $length=25) {
		if($url == "") return $url;
		if(preg_match("/^(http:\/\/)?([^\/]+)/i",$url, $matches)) {
			return substr($matches[2],$start,$length) . ((strlen($matches[2])>$start+$length)?"...":"");
		} else {
			return substr($url,$start,$length) . ((strlen($url)>$start+$length)?"...":"");
		}
}

/* realstats_timediff($time1,$time2)
 * 
 * someone said "use function- and variablename that speak for themselves"
 * here they are *G*
*/
function realstats_timediff($time1,$time2)
{
	$diff = $time2-$time1;
	$hrsDiff = 0; $minsDiff = 0; $secsDiff = 0;
      
	$sec_in_a_day = 60*60*24;
	$sec_in_an_hour = 60*60;
	while($diff >= $sec_in_an_hour){$hrsDiff++; $diff -= $sec_in_an_hour;}
	$sec_in_a_min = 60;
	while($diff >= $sec_in_a_min){$minsDiff++; $diff -= $sec_in_a_min;}
  $secsDiff = $diff;
	return sprintf("%02d h %02d m %02d s",$hrsDiff,$minsDiff,$secsDiff);

}

/* realstats_array_search_recursive( $needle, $haystack )
 *
 * speaks for itself, too
*/
function realstats_array_search_recursive( $needle, $haystack )
{
   $path = NULL;
   $keys = array_keys($haystack);
   while (!$path && (list($toss,$k)=each($keys))) {
     $v = $haystack[$k];
     if (is_scalar($v)) {
         if ($v===$needle) {
           $path = array($k);
         }
     } elseif (is_array($v)) {
         if ($path=realstats_array_search_recursive( $needle, $v )) {
           array_unshift($path,$k);
         }
     }
   }
   return $path;
}



/* useragent2array($useragent)
 * 
 * transforms useragent-string into an array, containing
 * the name of the browser and the name of the os
*/
function realstats_useragent2array($useragent) {
  //function and arrays taken from bbclone (http://bbclone.de)
  global $browser_array, $robot_array, $os_array;
  $connect = array();
  $returnarray = array();
  
  foreach (array("robot_array", "browser_array", "os_array") as $rule) {
    reset($$rule);

    while (list(${$rule."_name"}, ${$rule."_elem"}) = each($$rule)) {
      reset(${$rule."_elem"}['rule']);
    	while (list($pattern, $note) = each(${$rule."_elem"}['rule'])) {
        // eregi() is intentionally used because some php installations don't
        // know the "i" switch of preg_match() and would generate phony compile
        // error messages
        if (eregi($pattern, $useragent, $regs)) {
          $connect[$rule] = ${$rule."_name"};
          if (preg_match(":\\\\[0-9]{1}:" ,$note)) {
            $str = preg_replace(":\\\\([0-9]{1}):", "\$regs[\\1]", $note);
            eval("\$str = \"$str\";");
            $connect[$rule."_note"] = $str;
          }
          break 2;
        }
      }
    }
    if (!empty($connect['robot_array'])) break;
  }

  if(!empty($connect['robot_array'])) {
		$returnarray["browser"]=$robot_array[$connect['robot_array']]['title'] . (($connect['robot_array_note'])? " ".$connect['robot_array_note']:"");
		//if(!empty($uainfo['robot_array_note'])) $zugriffe[$i]["browser"].=" ".$uainfo['robot_array_note'];
		$returnarray["os"]=$returnarray["browser"];
		$returnarray["robot"]=true;
	} else {
		$returnarray["browser"]=$browser_array[$connect['browser_array']]['title'] . (($connect['browser_array_note'])? " ".$connect['browser_array_note']:"");
		$returnarray["os"]=$os_array[$connect['os_array']]['title'] . (($connect['os_array_note'])? " ".$connect['os_array_note']:"");
		$returnarray["robot"]=false;
	}
  return $returnarray;
  
}

/* realstats_url2searchstring($url)
 *
 * magic function to get the searchstring from an url
*/
function realstats_url2searchstring($url) {
	global $searchengine_array;
	$searchstring = "";
	$engine = "unknown";
	$decoded = urldecode($url);
	$temp = explode( '?', $decoded);
	foreach ($searchengine_array as $searchengine) {
		if(eregi(".*$searchengine[url].*", $temp[0])) {
			$chunks = explode( '&', $temp[1]);
			foreach ( $chunks as $pair ) {
				$param="";
				list($param, $value) = explode( '=', $pair);
				foreach ($searchengine[param] as $sparam) {
					if(eregi("^$sparam", $param)) {
						if($value != "") {
							list($sname) = array_keys($searchengine_array,$searchengine);
							$lastsearchstring['query']=$value;
							$lastsearchstring['engine']=$sname;
							$lastsearchstring['url']=$url;
							return $lastsearchstring;
						}
					} 
				}
			}
			list($sname) = array_keys($searchengine_array,$searchengine);
			return array('query'=>'?', 'engine'=>$sname, 'url'=>$url);
		}
	}
	return array('query'=>'?', 'engine'=>$unknown, 'url'=>$url);
}



/* function realstats_nicetitle($site, $querystring)
 * 
 * tries to compose a nice name for a site/querystring combination
*/
function realstats_nicetitle($site, $querystring) {
	global $tableposts, $wpdb;
	
	foreach (split("&", $querystring) as $query) {
		list($key,$value) = split("=", $query);
		$params[$key]=$value;
	}

  if( $site=="/wp-feed.php" || $site=="/index.php" || $site=="/wp-trackback.php" ) {
		if($params["category_name"]) {
			$nicetitle = "[Category " . trim($params["category_name"],"/") ."]";
		} elseif($params["author_name"]) {
			$nicetitle = "[Author " . trim($params["author_name"], "/") ."]";
		} elseif($querystring == "" || ($params["paged"] && count($params) == 1)) {
			$nicetitle = "Index of ". get_settings('blogname');
		} else {
			if($params["year"]) $where .= " AND YEAR(post_date)=" .$params["year"];
			if($params["monthnum"]) $where .= "	AND MONTH(post_date)=" .$params["monthnum"];
			if($params["day"]) $where .= "	AND DAYOFMONTH(post_date)=" .$params["day"];
			if($params["hour"]) $where .= "	AND HOUR(post_date)=" .$params["hour"];
			if($params["minute"]) $where .= "	AND MINUTE(post_date)=" .$params["minute"];
			if($params["second"]) $where .= "	AND SECOND(post_date)=" .$params["second"];
			if($params["name"]) $where .= "	AND post_name='" .$params["name"] ."'";
			if($params["p"]) $where .= "	AND ID=" .$params["p"];
			
			$rows = $wpdb->query("
				SELECT post_title FROM $tableposts
				WHERE 1=1
				$where");
			//echo "<p>$where</p>";
			if($rows==1) { $nicetitle = $wpdb->get_var(); } else { $nicetitle = "[Archive]"; }
		}
		if($site=="/wp-feed.php" && $params["feed"]) {
			if($rows!=1) $nicetitle="Index of ". get_settings('blogname');
			if($params["withcomments"]) {
				$nicetitle .= " (". $params["feed"] . "-feed with comments)";
			} else {
				$nicetitle .= " (". $params["feed"] . "-feed)";
			}
		}
		if($params["paged"]) {
			$nicetitle .= " (on page ". $params["paged"] .")";
		}
		if($site=="/wp-trackback.php") $nicetitle .= " (trackback)";
				
	} elseif($site=="/wp-comments-post.php") {
			$nicetitle = "[Commentpost]";
	} else {
		$nicetitle = realstats_url2shorturl($site);
	}
	return stripslashes($nicetitle);	
}



/* realstats_update_database()
 *
 * Inserts new hostnames in $table_wp_log_dns
 * Updates the visit_table with browser, os and the flags
 * Can be called anywhere, but usually takes a "lot" of time
*/
function realstats_update_database() {
	global $wpdb, $table_wp_log_visits, $table_wp_log_dns;

	$rows=0;
	/* get all unknown hostnames (better: the ips where the hostname is unknown) */
	$unknownhostnames = $wpdb->get_results("
	SELECT INET_NTOA(visits.IP) AS IPaddress
	FROM  $table_wp_log_visits as visits LEFT JOIN $table_wp_log_dns as dns ON visits.IP = dns.IP
	WHERE dns.IP IS NULL
	GROUP BY visits.IP");
	
	/* resolve ips */
	if(!empty($unknownhostnames)) {
		foreach ($unknownhostnames as $row) {
			//$wpdb->hide_errors();
			$rows2=$wpdb->query("INSERT INTO $table_wp_log_dns
			(IP, hostname) VALUES (INET_ATON('$row->IPaddress'), '".gethostbyaddr($row->IPaddress)."')");
			//$wpdb->show_errors();
			$rows++;
		}
	}
	return $rows;
}

/* realstats_zugriffe()
 * 
 * Gets some numbers (basic statistics) out of the database
*/
function realstats_getsomestats($whichstats = "all") {
	global $wpdb, $table_wp_log_hits, $table_wp_log_visits, $tablecomments, $tableposts;
	
	$gmtoffset = get_settings('gmt_offset');
	$mysqlnow = gmdate('Y-m-d H:i:s',time());
	$returnarray = array();
	
	switch (strtolower($whichstats)) {
	case "all":
		$where = "";
		$commentwhere = "";
		$postwhere = "";
		break;
	case "year":
		$where = " AND datetime > '$mysqlnow' - INTERVAL 1 YEAR";
		$commentwhere = " AND comment_date_gmt > '$mysqlnow' - INTERVAL 1 YEAR";
		$postwhere = " AND post_date_gmt > '$mysqlnow' - INTERVAL 1 YEAR";
		break;
	case "month":
		$where = " AND datetime > '$mysqlnow' - INTERVAL 1 MONTH";
		$commentwhere = " AND comment_date_gmt > '$mysqlnow' - INTERVAL 1 MONTH";
		$postwhere = " AND post_date_gmt > '$mysqlnow' - INTERVAL 1 MONTH";
		break;
	case "monthbefore":
		$where = " AND (datetime <= '$mysqlnow' - INTERVAL 1 MONTH AND datetime > '$mysqlnow' - INTERVAL 2 MONTH)";
		$commentwhere = " AND (comment_date_gmt <= '$mysqlnow' - INTERVAL 1 MONTH AND comment_date_gmt > '$mysqlnow' - INTERVAL 2 MONTH)";
		$postwhere = " AND (post_date_gmt <= '$mysqlnow' - INTERVAL 1 MONTH AND post_date_gmt > '$mysqlnow' - INTERVAL 2 MONTH)";
		break;
	case "week":
		$where = " AND datetime > '$mysqlnow' - INTERVAL 7 DAY";
		$commentwhere = " AND comment_date_gmt > '$mysqlnow' - INTERVAL 7 DAY";
		$postwhere = " AND post_date_gmt > '$mysqlnow' - INTERVAL 7 DAY";
		break;
	case "weekbefore":
		$where = " AND (datetime <= '$mysqlnow' - INTERVAL 7 DAY AND datetime > '$mysqlnow' - INTERVAL 14 DAY)";
		$commentwhere = " AND (comment_date_gmt <= '$mysqlnow' - INTERVAL 7 DAY AND comment_date_gmt > '$mysqlnow' - INTERVAL 14 DAY)";
		$postwhere = " AND (post_date_gmt <= '$mysqlnow' - INTERVAL 7 DAY AND post_date_gmt > '$mysqlnow' - INTERVAL 14 DAY)";
		break;
	case "day":
		$where = " AND datetime > '$mysqlnow' - INTERVAL 1 DAY";
		$commentwhere = " AND comment_date_gmt > '$mysqlnow' - INTERVAL 1 DAY";
		$postwhere = " AND post_date_gmt > '$mysqlnow' - INTERVAL 1 DAY";
		break;
	case "daybefore":
		$where = " AND (datetime <= '$mysqlnow' - INTERVAL 1 DAY AND datetime > '$mysqlnow' - INTERVAL 2 DAY)";
		$commentwhere = " AND (comment_date_gmt <= '$mysqlnow' - INTERVAL 1 DAY AND comment_date_gmt > '$mysqlnow' - INTERVAL 2 DAY)";
		$postwhere = " AND (post_date_gmt <= '$mysqlnow' - INTERVAL 1 DAY AND post_date_gmt > '$mysqlnow' - INTERVAL 2 DAY)";
		break;
	default:
		$where = " AND datetime > '$mysqlnow' - INTERVAL 1 HOUR";
		$commentwhere = " AND comment_date_gmt > '$mysqlnow' - INTERVAL 1 HOUR";
		$postwhere = " AND post_date_gmt > '$mysqlnow' - INTERVAL 1 HOUR";
		break;
	}
	
	
	$results = $wpdb->get_results("
			SELECT unix_timestamp(Min(datetime) + INTERVAL $gmtoffset HOUR) as since, Count(*) as hits, Count(DISTINCT visits.visitID) as visits, Count(DISTINCT ip) as ips, Count(DISTINCT referrer) as referrers, Count(DISTINCT useragent) as useragents, Count(DISTINCT browser) as browsers, Count(DISTINCT os) as oss
	 		FROM $table_wp_log_hits as hits INNER JOIN $table_wp_log_visits as visits ON hits.visitID = visits.visitID
	 		WHERE flags <> 'robot'
	 		$where
	 		LIMIT 1");
	foreach ($results as $row) {
			$returnarray["datetime"]=$row->since;
			$returnarray["humans_hits"]=$row->hits;
			$returnarray["humans_visits"]=$row->visits;
			$returnarray["humans_ips"]=$row->ips;
			$returnarray["humans_referrers"]=$row->referrers;
			$returnarray["humans_useragents"]=$row->useragents;
			$returnarray["humans_browsers"]=$row->browsers;
			$returnarray["humans_oss"]=$row->oss;
	}
		
	$results = $wpdb->get_results("
			SELECT Count(*) as hits, Count(DISTINCT visits.visitID) as visits, Count(DISTINCT ip) as ips, Count(DISTINCT referrer) as referrers, Count(DISTINCT useragent) as useragents, Count(DISTINCT browser) as browsers, Count(DISTINCT os) as oss
	 		FROM $table_wp_log_hits as hits INNER JOIN $table_wp_log_visits as visits ON hits.visitID = visits.visitID
	 		WHERE flags = 'robot'
	 		$where
	 		LIMIT 1");
	foreach ($results as $row) {
			$returnarray["robots_hits"]=$row->hits;
			$returnarray["robots_visits"]=$row->visits;
			$returnarray["robots_ips"]=$row->ips;
			$returnarray["robots_referrers"]=$row->referrers;
			$returnarray["robots_useragents"]=$row->useragents;
			$returnarray["robots_browsers"]=$row->browsers;
			$returnarray["robots_oss"]=$row->oss;

			$returnarray["hits"]=$returnarray["humans_hits"]+$returnarray["robots_hits"];
			$returnarray["visits"]=$returnarray["humans_visits"]+$returnarray["robots_visits"];
			$returnarray["ips"]=$returnarray["humans_ips"]+$returnarray["robots_ips"];
			$returnarray["referrers"]=$returnarray["humans_referrers"]+$returnarray["robots_referrers"];
			$returnarray["useragents"]=$returnarray["humans_useragents"]+$returnarray["robots_useragents"];
			$returnarray["browsers"]=$returnarray["humans_browsers"]+$returnarray["robots_browsers"];
			$returnarray["oss"]=$returnarray["humans_oss"]+$returnarray["robots_oss"];
	}
	
	$results = $wpdb->get_results("
	 		SELECT Count(*) as posts
	 		FROM $tableposts
	 		WHERE 1
	 		$postwhere
	 		LIMIT 1");
	foreach ($results as $row) {
			$returnarray["posts"]=$row->posts;
	}	 		

	$results = $wpdb->get_results("
	 		SELECT Count(*) as comments
	 		FROM $tablecomments
	 		WHERE 1
	 		$commentwhere
	 		LIMIT 1");
	foreach ($results as $row) {
			$returnarray["comments"]=$row->comments;
	}	 		
	
	return $returnarray;
}

/* realstats_getvisits($limit=100)
 *
 * returns an array with the last $limit visits
*/
function realstats_getvisits($limit=100) {
	global $wpdb, $table_wp_log_visits, $table_wp_log_hits, $table_wp_log_dns, $robot_array, $browser_array, $os_array;
	
	$visits = array();
	$results = $wpdb->get_results("SELECT DISTINCT *, unix_timestamp(max(datetime)) as utime, count(hitID) as hits
	FROM ($table_wp_log_visits as visits INNER JOIN $table_wp_log_hits as hits ON visits.visitID = hits.visitID) LEFT JOIN $table_wp_log_dns as dns ON visits.IP = dns.IP
	GROUP BY visits.visitID
	ORDER BY utime DESC LIMIT $limit");
	$i=0;
	foreach ($results as $row) {
		$visits[$i]["id"]=$row->visitID;
		$visits[$i]["IP"]=$row->IP;
		$visits[$i]["hostname"]=$row->hostname;
		$visits[$i]["hits"]=$row->hits;
		$visits[$i]["datetime"]=$row->utime + get_settings('gmt_offset')*3600;
		$visits[$i]["referrer"]=$row->referrer;
		$visits[$i]["referrer_short"]=realstats_url2shorturl($row->referrer);
		$visits[$i]["browser"]=$row->browser;
		$visits[$i]["os"]=$row->os;
		$visits[$i]["robot"]=($row->flags=="robot");
		$visits[$i]["user"]=stripslashes(($row->comment_author != "")?$row->comment_author:$row->wordpressuser);
		$i++;
	}
	return $visits;
}

/* realstats_gethits($visitID, $limit=100)
 *
 * returns the hits belonging to a specific visit
*/
function realstats_gethits($visitID, $limit=100) {
	global $wpdb, $table_wp_log_visits, $table_wp_log_hits, $table_wp_log_dns, $robot_array, $browser_array, $os_array;
	
	$hits = array();
	$results = $wpdb->get_results("SELECT *, unix_timestamp(datetime) as utime
	FROM $table_wp_log_visits as visits, $table_wp_log_hits as hits, $table_wp_log_dns as dns
	WHERE visits.visitID = hits.visitID
	AND visits.IP = dns.IP
	AND visits.visitID = $visitID
	ORDER BY datetime ASC LIMIT $limit");
	$i=0;
	foreach ($results as $row) {
		$hits[$i]["id"]=$row->visitID;
		$hits[$i]["IP"]=long2ip($row->IP);
		$hits[$i]["useragent"]=$row->useragent;
		$temparray=realstats_useragent2array($row->useragent);
		$hits[$i]["browser"]=$temparray["browser"];
		$hits[$i]["os"]=$temparray["os"];
		$hits[$i]["robot"]=$temparray["robot"];
		#$hits[$i]["browser"]=$row->browser;
		#$hits[$i]["os"]=$row->os;
		#$hits[$i]["robot"]=($row->flags=="robot");
		$hits[$i]["user"]=stripslashes(($row->comment_author != "")?$row->comment_author:$row->wordpressuser);
		$hits[$i]["hostname"]=$row->hostname;
		$hits[$i]["datetime"]=$row->utime + get_settings('gmt_offset')*3600;
		$hits[$i]["title"]=realstats_nicetitle($row->site,$row->querystring);
		$hits[$i]["url"]="$row->site?$row->querystring";
		$hits[$i]["url_short"]=realstats_url2shorturl($row->site);
		$hits[$i]["referrer"]=$row->referrer;
		$hits[$i]["referrer_short"]=realstats_url2shorturl($row->referrer);
		$i++;
	}
	return $hits;	
}

/* realstats_getlastcommentauthors($limit = 20)
 *
 * returns the $limit last comment authors
*/
function realstats_getlastcommentauthors($limit = 20) {
	global $wpdb, $table_wp_log_hits, $table_wp_log_visits;
	
	$lastcommentauthors = array();
	
	$results = $wpdb->get_results("
	SELECT comment_author, max(unix_timestamp(datetime)) AS maxdt
	FROM  $table_wp_log_hits as hits, $table_wp_log_visits as visits
	WHERE hits.visitID = visits.visitID
	AND comment_author NOT LIKE  ''
	GROUP  BY comment_author
	ORDER  BY maxdt DESC
	LIMIT $limit");
	
	$i=0;
	foreach ($results as $row) {
		$lastcommentauthors[$i][comment_author]=stripslashes($row->comment_author);
		$lastcommentauthors[$i][datetime]=($row->maxdt + get_settings('gmt_offset')*3600);
		$i++;
	}
	return $lastcommentauthors;
}

function realstats_getlastreferrers($limit = 20) {
	global $wpdb, $table_wp_log_hits, $realstats_dont_include_in_referrers;
	
	$lastreferrers = array();
	$where="";
	foreach($realstats_dont_include_in_referrers as $url) {
		$where .= " AND referrer NOT LIKE '%$url%'";
	}
	
	$results = $wpdb->get_results("
	SELECT referrer, unix_timestamp(datetime) AS maxdt
	FROM  $table_wp_log_hits
	WHERE referrer NOT LIKE  ''
	$where
	GROUP  BY YEAR( datetime ) , MONTH( datetime ) , DAYOFMONTH( datetime ) ,  HOUR ( datetime ), MINUTE( datetime ), referrer
	ORDER  BY datetime DESC
	LIMIT $limit");
	
	$i=0;
	foreach ($results as $row) {
		$lastreferrers[$i][referrer]=$row->referrer;
		$lastreferrers[$i][referrer_short]=realstats_url2shorturl($row->referrer);
		$lastreferrers[$i][datetime]=$row->maxdt + get_settings('gmt_offset')*3600;
		$i++;
	}
	return $lastreferrers;
}



/* function realstats_gettimearray()
 *
 * returns an array for the timestats admin-page
*/
function realstats_gettimearray($type="hours", $number=24, $order="DESC", $bots=false) {
	global $wpdb, $table_wp_log_hits, $table_wp_log_visits;
	
	$returnarray = array();
	$mysqlnow = gmdate('Y-m-d H:i:s',time());
	$gmtoffset = get_settings('gmt_offset');
	$i=0;
	if($bots == true) {
	    $wherestring = "";	
	} else {
	    $wherestring = "AND flags <> 'robot'";
	}

	if($type=="hours") {
		$results = $wpdb->get_results("
		SELECT DATE_FORMAT(datetime + INTERVAL $gmtoffset HOUR, '%H') as descr, count(DISTINCT hitID) as hits, count(DISTINCT $table_wp_log_hits.visitID) as visits
		FROM $table_wp_log_hits INNER JOIN $table_wp_log_visits ON $table_wp_log_hits.visitID = $table_wp_log_visits.visitID
		WHERE datetime > NOW() - INTERVAL $gmtoffset+$number+1 HOUR
		$wherestring
		GROUP BY DAYOFMONTH(datetime + INTERVAL $gmtoffset HOUR), HOUR(datetime + INTERVAL $gmtoffset HOUR)
		ORDER BY datetime DESC
		LIMIT $number");
	
	} elseif($type=="days") {
		$results = $wpdb->get_results("
		SELECT DATE_FORMAT(datetime + INTERVAL $gmtoffset HOUR, '%d') as descr, count(*) as hits, count(DISTINCT $table_wp_log_hits.visitID) as visits
		FROM $table_wp_log_hits INNER JOIN $table_wp_log_visits ON $table_wp_log_hits.visitID = $table_wp_log_visits.visitID
		WHERE datetime > '$mysqlnow' - INTERVAL $number+1 DAY
		$wherestring
		GROUP BY MONTH(datetime + INTERVAL $gmtoffset HOUR), DAYOFMONTH(datetime + INTERVAL $gmtoffset HOUR)
		ORDER BY datetime DESC
		LIMIT $number");
	
	} elseif($type=="days2") {
		$results = $wpdb->get_results("
		SELECT DATE_FORMAT(datetime + INTERVAL $gmtoffset HOUR, '%a') as descr, count(*) as hits, count(DISTINCT $table_wp_log_hits.visitID) as visits
		FROM $table_wp_log_hits INNER JOIN $table_wp_log_visits ON $table_wp_log_hits.visitID = $table_wp_log_visits.visitID
		WHERE datetime > '$mysqlnow' - INTERVAL $number+1 DAY
		$wherestring
		GROUP BY MONTH(datetime + INTERVAL $gmtoffset HOUR), DAYOFMONTH(datetime + INTERVAL $gmtoffset HOUR)
		ORDER BY datetime DESC
		LIMIT $number");

	} elseif($type=="months") {
		$results = $wpdb->get_results("
		SELECT DATE_FORMAT(datetime + INTERVAL $gmtoffset HOUR, '%b') as descr, count(*) as hits, count(DISTINCT $table_wp_log_hits.visitID) as visits
		FROM $table_wp_log_hits INNER JOIN $table_wp_log_visits ON $table_wp_log_hits.visitID = $table_wp_log_visits.visitID
		WHERE datetime > '$mysqlnow' - INTERVAL $number+1 MONTH
		$wherestring
		GROUP BY YEAR(datetime + INTERVAL $gmtoffset HOUR), MONTH(datetime + INTERVAL $gmtoffset HOUR)
		ORDER BY datetime DESC
		LIMIT $number");

	} else {	
		return 0;
	}
	foreach($results as $row) { $returnarray[]=array(descr=>$row->descr, hits=>$row->hits, visits=>$row->visits); }
	$returnarray = array_pad($returnarray, (($mysqlorder=="DESC")?$number:$number*-1), array(descr=>"n/a", hits=>0, visits=>0));		
	if($order!="DESC") krsort($returnarray);
	return $returnarray;		
}


function realstats_getlastsearchstrings($limit = 20) {
	global $wpdb, $table_wp_log_hits, $table_wp_log_visits, $searchengine_array;
	
	$lastsearchstrings = array();
	
	$where = "";
	foreach ($searchengine_array as $engine) {
		$where .= " OR referrer LIKE '%$engine[url]%'";
	}
	
	$results = $wpdb->get_results("
	SELECT unix_timestamp(datetime) as utime, referrer FROM $table_wp_log_hits 
	WHERE 1=2
	$where
	ORDER BY datetime DESC
	LIMIT $limit
	");
	/*
	GROUP  BY YEAR( datetime ) , MONTH( datetime ) , DAYOFMONTH( datetime ) ,  HOUR ( datetime ), MINUTE( datetime ), referrer
	*/
	
	$i=0;
	foreach ($results as $row) {
		$lastsearchstrings[$i]=realstats_url2searchstring($row->referrer);
		$lastsearchstrings[$i][datetime]=$row->utime + get_settings('gmt_offset')*3600;
		$i++;
	}
	return $lastsearchstrings;
}

function realstats_getusersonline($since = 10) {
    global $wpdb, $table_wp_log_visits, $table_wp_log_hits;
    
    $usersonline = array();
    $mysqlnow = gmdate('Y-m-d H:i:s',time());
    $gmtoffset = get_settings('gmt_offset');
    
    $results = $wpdb->get_results("
    SELECT comment_author as name, unix_timestamp(max(datetime)) as lastseen
    FROM $table_wp_log_visits as visits JOIN $table_wp_log_hits as hits ON visits.visitid = hits.visitid
    WHERE datetime > '$mysqlnow' - INTERVAL $since MINUTE
    AND comment_author NOT LIKE ''
    AND flags <> 'robot'
    GROUP BY comment_author
    ORDER BY lastseen DESC
    ");
    
    if($results)
    foreach ($results as $row) {
	$usersonline[humans][]=$row->name;
    }
    $usersonline[humancount]=count($usersonline[humans]);
    
    $results = $wpdb->get_results("
    SELECT browser as name, unix_timestamp(max(datetime)) as lastseen
    FROM $table_wp_log_visits as visits JOIN $table_wp_log_hits as hits ON visits.visitid = hits.visitid
    WHERE datetime > '$mysqlnow' - INTERVAL $since MINUTE
    AND flags = 'robot'
    GROUP BY browser
    ORDER BY lastseen DESC
    ");
    
    if($results)
    foreach ($results as $row) {
	$usersonline[robots][]=$row->name;
    }
    $usersonline[robotcount]=count($usersonline[robots]);
    
    $usersonline[guestcount] = $wpdb->get_var("
    SELECT count(visits.visitid) as guestcount
    FROM $table_wp_log_visits as visits JOIN $table_wp_log_hits as hits ON visits.visitid = hits.visitid
    WHERE datetime > '$mysqlnow' - INTERVAL $since MINUTE
    AND comment_author LIKE ''
    AND flags <> 'robot'
    GROUP BY useragent, IP
    ");
    
    if(!$usersonline[guestcount]) $usersonline[guestcount]=0;
    return $usersonline;    
}


?>