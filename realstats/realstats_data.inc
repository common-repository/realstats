<?php
/* This file is essentially a copy of the files os.php, browser.php and
 * robot.php of the bbclone project (http://bbclone.de). It is needed
 * to convert those useragent-strings to usefull data :-) 
*/ 


/*********** DDDD   AAA  TTTTT  AAA  ***********
 *********** D   D A   A   T   A   A ***********
 *********** D   D AAAAA   T   AAAAA ***********
 *********** D   D A   A   T   A   A ***********
 *********** DDDD  A   A   T   A   A ***********
*/

$searchengine_array = array(
	"Google" => array(
		"url" => "google.",
		"param" => array("as_q", "q", "as_epq")
	),
	"AOL" => array(
		"url" => "aolsearch.aol.",
		"param" => array("query", "encquery")
	),
	"T-Online Germany" => array(
		"url" => "brisbane.t-online.de",
		"param" => array("q")
	),
	"Lycos Germany" => array(
		"url" => "suche.lycos.",
		"param" => array("query")
	),
	"Yahoo" => array(
		"url" => "yahoo.",
		"param" => array("p")
	),
	"Abacho" => array(
		"url" => "abacho.",
		"param" => array("q")
	),
	"Fireball.de" => array(
		"url" => "suche.fireball.de",
		"param" => array("query")
	),
	"Altavista" => array(
		"url" => "altavista.",
		"param" => array("q")
	),
	"Web.de" => array(
		"url" => "suche.web.de",
		"param" => array("su")
	),
	"Feedster" => array(
		"url" => "feedster.com",
		"param" => array("q")
	),
	"Alltheweb" => array(
		"url" => "alltheweb.com",
		"param" => array("q")
	),
	"Comcast" => array(
		"url" => "comcast.net",
		"param" => array("query")
	),
	"Abacho" => array(
		"url" => "search.abacho.com",
		"param" => array("q")
	),
	"MSN" => array(
		"url" => "search.msn.",
		"param" => array("q")
	)
);
/*TEMPLATE
	"" => array(
		"url" => array(""),
		"param" => array("")
	),
*/


$browser_array = array(
  "abrowse" => array(
    "icon" => "abrowse",
    "title" => "ABrowse",
    "rule" => array(
      "abrowse[ /\-]([0-9.]+)" => "\\1",
      "abrowse" => ""
    )
  ),
  "amaya" => array(
    "icon" => "amaya",
    "title" => "Amaya",
    "rule" => array(
      "amaya/([0-9.]+)" => "\\1",
    )
  ),
  "aol" => array(
    "icon" => "aol",
    "title" => "AOL",
    "rule" => array(
      "aol[ /\-]([0-9.]+)" => "\\1",
      "aol[ /\-]?browser" => ""
    )
  ),
  "avantbrowser" => array(
    "icon" => "avantbrowser",
    "title" => "Avant Browser",
    "rule" => array(
      "Avant[ ]?Browser" => ""
    )
  ),
  "avantgo" => array(
    "icon" => "avantgo",
    "title" => "AvantGo",
    "rule" => array(
      "AvantGo[ /]([0-9.]+)" => "\\1"
    )
  ),
  "beonex" => array(
    "icon" => "beonex",
    "title" => "Beonex",
    "rule" => array(
      "beonex/([0-9.]+)" => "\\1",
    )
  ),
  "camino" => array(
    "icon" => "camino",
    "title" => "Camino",
    "rule" => array(
      "camino/([0-9.+]+)" => "\\1"
    )
  ),
  "chimera" => array(
    "icon" => "chimera",
    "title" => "Chimera",
    "rule" => array(
      "chimera/([0-9.+]+)" => "\\1",
    )
  ),
  "columbus" => array(
    "icon" => "columbus",
    "title" => "Columbus",
    "rule" => array(
      "columbus[ /]([0-9.]+)" => "\\1"
    )
  ),
  "crazybrowser" => array(
    "icon" => "crazybrowser",
    "title" => "Crazy Browser",
    "rule" => array(
      "Crazy Browser[ /]([0-9.]+)" => "\\1"
    )
  ),
  "curl" => array(
    "icon" => "curl",
    "title" => "Curl",
    "rule" => array(
      "curl[ /]([0-9.]+)" => "\\1"
    )
  ),
  "dillo" => array(
    "icon" => "dillo",
    "title" => "Dillo",
    "rule" => array(
      "dillo/([0-9.]+)" => "\\1",
    )
  ),
  "doris" => array(
    "icon" => "doris",
    "title" => "Doris",
    "rule" => array(
      "Doris/([0-9.]+)" => "\\1",
    )
  ),
  "Elinks" => array(
    "icon" => "links",
    "title" => "ELinks",
    "rule" => array(
      "ELinks[ /][\(]*([0-9.]+)" => "\\1"
    )
  ),
  "Epiphany"  => array(
    "icon"  => "epiphany",
    "title" => "Epiphany",
    "rule"  => array(
      "Epiphany/([0-9.]+)" => "\\1"
    )
  ),
  "firebird"  => array(
    "icon"  => "firebird",
    "title" => "Firebird",
    "rule"  => array(
      "Firebird/([0-9.+]+)" => "\\1"
    )
  ),
  "firefox"  => array(
    "icon"  => "firefox",
    "title" => "Firefox",
    "rule"  => array(
      "Firefox/([0-9.+]+)" => "\\1"
    )
  ),
  "galeon" => array(
    "icon" => "galeon",
    "title" => "Galeon",
    "rule" => array(
      "galeon/([0-9.]+)" => "\\1",
    )
  ),
  "ibrowse" => array(
    "icon" => "ibrowse",
    "title" => "IBrowse",
    "rule" => array(
      "ibrowse[ /]([0-9.]+)" => "\\1",
      "ibrowse" => ""
    )
  ),
  "icab" => array(
    "icon" => "icab",
    "title" => "iCab",
    "rule" => array(
      "icab/([0-9.]+)" => "\\1",
    )
  ),
  "isilox" => array(
    "icon" => "isilox",
    "title" => "iSiloX",
    "rule" => array(
      "iSilox/([0-9.]+)" => "\\1",
    )
  ),
  "java" => array(
    "icon" => "java",
    "title" => "Java",
    "rule" => array(
      "java[ /]([0-9.]+)" => "\\1",
      "java" => ""
    )
  ),
  "lotus" => array(
    "icon" => "lotus",
    "title" => "Lotus Notes",
    "rule" => array(
      "Lotus[ \-]?Notes[ /]([0-9.]+)" => "\\1"
    )
  ),
  "k-meleon" => array(
    "icon" => "k-meleon",
    "title" => "K-Meleon",
    "rule" => array(
      "K-Meleon[ /]([0-9.]+)" => "\\1"
    )
  ),
  "konqueror" => array(
    "icon" => "konqueror",
    "title" => "Konqueror",
    "rule" => array(
      "konqueror/([0-9.]+)" => "\\1"
    )
  ),
  "links" => array(
    "icon" => "links",
    "title" => "Links",
    "rule" => array(
      "Links[ /]\(([0-9.]+)" => "\\1"
    )
  ),
  "lunascape" => array(
    "icon" => "lunascape",
    "title" => "Lunascape",
    "rule" => array(
      "Lunascape[ /]([0-9.]+)" => "\\1",
    )
  ),
  "lynx" => array(
    "icon" => "lynx",
    "title" => "Lynx",
    "rule" => array(
      "lynx/([0-9a-z.]+)" => "\\1"
    )
  ),
  "mbrowser" => array(
    "icon" => "mbrowser",
    "title" => "mBrowser",
    "rule" => array(
      "mBrowser[ /]([0-9.]+)" => "\\1",
    )
  ),
  "mosaic" => array(
    "icon" => "mosaic",
    "title" => "Mosaic",
    "rule" => array(
      "mosaic[ /]([0-9.]+)" => "\\1",
    )
  ),
  "nautilus" => array(
    "icon" => "nautilus",
    "title" => "Nautilus",
    "rule" => array(
      "nautilus/([0-9.]+)" => "\\1",
      "gnome[ \-]?vfs/([0-9.]+)" => "\\1",
    )
  ),
  "netcaptor" => array(
    "icon" => "netcaptor",
    "title" => "Netcaptor",
    "rule" => array(
      "netcaptor[ /]([0-9.]+)" => "\\1",
    )
  ),
  "netpositive" => array(
    "icon" => "netpositive",
    "title" => "NetPositive",
    "rule" => array(
      "netpositive[ /]([0-9.]+)" => "\\1"
    )
  ),
  "omniweb" => array(
    "icon" => "omniweb",
    "title" => "OmniWeb",
    "rule" => array(
      "omniweb/[ a-z]?([0-9.]+)$" => "\\1"
    )
  ),
  "opera" => array(
    "icon" => "opera",
    "title" => "Opera",
    "rule" => array(
      "opera[ /]([0-9.]+)" => "\\1"
    )
  ),
  "plink" => array(
    "icon" => "plink",
    "title" => "PLink",
    "rule" => array(
      "PLink[ /]([0-9a-z.]+)" => "\\1"
    )
  ),
  "phoenix" => array(
    "icon" => "phoenix",
    "title" => "Phoenix",
    "rule" => array(
      "Phoenix/([0-9.+]+)" => "\\1"
    )
  ),
  "safari" => array(
    "icon" => "safari",
    "title" => "Safari",
    "rule" => array(
      "safari/([0-9.]+)" => "\\1",
    )
  ),
  "shiira" => array(
    "icon" => "shiira",
    "title" => "Shiira",
    "rule" => array(
      "Shiira/([0-9.]+)" => "\\1",
    )
  ),
  "sleipnir" => array(
    "icon" => "sleipnir",
    "title" => "Sleipnir",
    "rule" => array(
      "Sleipnir( Version)?[ /]([0-9.]+)" => "\\2"
    )
  ),
  "slimbrowser" => array(
    "icon" => "slimbrowser",
    "title" => "SlimBrowser",
    "rule" => array(
      "Slimbrowser" => ""
    )
  ),
  "staroffice" => array(
    "icon" => "staroffice",
    "title" => "StarOffice",
    "rule" => array(
      "staroffice[ /]([0-9.]+)" => "\\1"
    )
  ),
  "voyager" => array(
    "icon" => "voyager",
    "title" => "Voyager",
    "rule" => array(
      "voyager[ /]([0-9.]+)" => "\\1"
    )
  ),
  "w3m" => array(
    "icon" => "w3m",
    "title" => "w3m",
    "rule" => array(
      "w3m/([0-9.]+)" => "\\1"
    )
  ),
  "webtv" => array(
    "icon" => "webtv",
    "title" => "Webtv",
    "rule" => array(
      "webtv[ /]([0-9.]+)" => "\\1",
      "webtv" => ""
    )
  ),
  "wwwc" => array(
    "icon" => "wwwc",
    "title" => "WWWC",
    "rule" => array(
      "WWWC[ /]([0-9.]+)" => "\\1",
    )
  ),
// Catch up for the originals. they got to stay in that order.
  "libwww" => array(
    "icon" => "libwww",
    "title" => "libWWW",
    "rule" => array(
      "libww(w|w-perl|w-FM)[ /]([0-9.]+)" => "\\2",
      "libww(w|w-perl|w-FM)" => ""
    )
  ),
  "explorer" => array(
    "icon" => "explorer", 
    "title" => "Explorer",
    "rule" => array(
      "MSIE[ /]([0-9.]+)" => "\\1"
    )
  ),
  "netscape" => array(
    "icon" => "netscape",
    "title" => "Netscape",
    "rule" => array(
      "netscape[0-9]?/([0-9.]+)" => "\\1",
      "mozilla/([0-4][0-9.]+)" => "\\1"
    )
  ),
  "mozilla" => array(
    "icon" => "mozilla",
    "title" => "Mozilla",
    "rule" => array(
      "mozilla/[5-9][0-9.]+.+rv:([0-9a-z.+]+)" => "\\1",
      "mozilla/([5-9][0-9a-z.]+)" => "\\1"
    )
  ),
//sebbi.de stuff
  "newsgator" => array(
    "icon" => "newsgator",
    "title" => "NewsGator",
    "rule" => array(
      "NewsGator/([0-9][0-9.]+)" => "\\1"
    )
  ),
  "sharpreader" => array(
    "icon" => "sharpreader",
    "title" => "SharpReader",
    "rule" => array(
      "SharpReader/([0-9][0-9.]+)" => "\\1"
    )
  ),
// Things we don't know by now
  "other" => array(
    "icon" => "question",
    "title" => "other",
    "rule" => array(
      ".+" => ""
    )
  )
);

$robot_array = array(
  "about" => array(
    "icon" => "about",
    "title" => "About",
    "rule" => array(
      "Libby[_/ ]([0-9.]+)" => "\\1"
    )
  ),
  "acoon" => array(
    "icon" => "acoon",
    "title" => "Acoon",
    "rule" => array(
      "Acoon[ \-]?Robot" => ""
    )
  ),
  "alexa" => array(
    "icon" => "alexa",
    "title" => "Alexa",
    "rule" => array(
      "ia_archive" => ""
    )
  ),
  "almaden" => array(
    "icon" => "robot",
    "title" => "IBM Crawler",
    "rule" => array(
      "www\.almaden\.ibm\.com/cs/crawler" => ""
    )
  ),
  "altavista" => array(
    "icon" => "altavista",
    "title" => "Altavista",
    "rule" => array(
      "Scooter[ /\-]*[a-z]*([0-9.]+)" => "\\1",
    )
  ),
  "amphetameme" => array(
    "icon" => "robot",
    "title" => "Amphetameme",
    "rule" => array(
      "amphetameme[ \-]?crawler" => ""
    )
  ),
  "appie" => array(
    "icon" => "robot",
    "title" => "Appie",
    "rule" => array(
      "appie[ /]?([0-9.]+)" => "\\1"
    )
  ),
  "ask" => array(
    "icon" => "askjeeves",
    "title" => "Ask Jeeves",
    "rule" => array(
      "Ask[ \-]?Jeeves" => "",
    )
  ),
  "axel" => array(
    "icon" => "robot",
    "title" => "Axel",
    "rule" => 
    array(
      "axel" => ""
    )
  ),  "answerbus" => array(
    "icon" => "robot",
    "title" => "AnswerBus",
    "rule" => 
    array(
      "answerbus" => ""
    )
  ),
  "augurnfind" => array(
    "icon" => "robot",
    "title" => "Augurnfind",
    "rule" => 
    array(
      "augurnfind[/ ][v\-]*([0-9.]+)" => "\\1"
    )
  ),
  "baidu" => array(
    "icon" => "baidu",
    "title" => "Baidu",
    "rule" => array(
      "Baiduspider" => ""
    )
  ),
  "bananatree" => array(
    "icon" => "robot",
    "title" => "BananaTree",
    "rule" => array(
      "www\.thebananatree\.org" => ""
    )
  ),
  "bitbeamer" => array(
    "icon" => "bitbeamer",
    "title" => "BitBeamer",
    "rule" => array(
      "BitBeamer/([0-9.]+)" => "\\1"
    )
  ),
  "blogbot" => array(
    "icon" => "robot",
    "title" => "BlogBot",
    "rule" => array(
      "Blog[ \-]?Bot" => ""
    )
  ),
  "blogmap" => array(
    "icon" => "robot",
    "title" => "Blogmap",
    "rule" => array(
      "blogmap" => ""
    )
  ),
  "blogosphere" => array(
    "icon" => "robot",
    "title" => "Blogosphere",
    "rule" => array(
      "Blogosphere" => ""
    )
  ),
  "blogpulse" => array(
    "icon" => "robot",
    "title" => "Blogpulse",
    "rule" => array(
      "Blogpulse" => ""
    )
  ),
  "blogs" => array(
    "icon" => "robot",
    "title" => "Blo.gs",
    "rule" => array(
      "blo\.gs[ /]?([0-9.]+)" => "\\1",
      "blo\.gs" => ""
      
    )
  ),
  "blogshares" => array(
    "icon" => "robot",
    "title" => "BlogShares",
    "rule" => array(
      "BlogShares[ ]?Bot[ /]?([0-9.]+)" => "\\1",
      "BlogShares\)[ /]?V([0-9.]+)" => "\\1"
    )
  ),
  "blogtick" => array(
    "icon" => "robot",
    "title" => "BlogTick",
    "rule" => array(
      "BlogTickServer" => ""
    )
  ),
  "bobby" => array(
    "icon" => "bobby",
    "title" => "Bobby",
    "rule" => array(
      "bobby[ /]?([0-9.]+)" => "\\1",
    )
  ),
  "boitho" => array(
    "icon" => "robot",
    "title" => "Boitho",
    "rule" => array(
      "Boitho\.com[ \-]?robot" => ""
    )
  ),
  "book" => array(
    "icon" => "book",
    "title" => "Bookmark",
    "rule" => array(
      "\[http://www\.bookmark\.ne\.jp/\]" => ""
    )
  ),
  "bordermanager" => array(
    "icon" => "bordermanager",
    "title" => "Border Manager",
    "rule" => array(
      "BorderManager[ /]?([0-9.]+)" => "\\1"
    )
  ),
  "browserspy" => array(
    "icon" => "robot",
    "title" => "BrowserSpy",
    "rule" => array(
      "BrowserSpy" => ""
    )
  ),
  "bruno" => array(
    "icon" => "robot",
    "title" => "Bruno",
    "rule" => array(
      "Bruno" => ""
    )
  ),
  "btbot" => array(
    "icon" => "robot",
    "title" => "BitTorrent",
    "rule" => array(
      "BTbot/([0-9.]+)" => "\\1"
    )
  ),
  "claymont" => array(
    "icon" => "claymont",
    "title" => "Claymont",
    "rule" => array(
      "claymont\.com" => ""
    )
  ),
  "clush" => array(
    "icon" => "clush",
    "title" => "Clush",
    "rule" => array(
      "Clustered-Search-Bot[ /]?([0-9.]+)" => "\\1",
    )
  ),
  "combot" => array(
    "icon" => "robot",
    "title" => "comBot",
    "rule" => array(
      "comBot[ /]?([0-9.]+)" => "\\1",
    )
  ),
  "commerobo" => array(
    "icon" => "robot",
    "title" => "Commerobo",
    "rule" => array(
      "Commerobo/([0-9.]+)" => "\\1"
    )
  ),
  "cosmos" => array(
    "icon" => "robot",
    "title" => "Cosmos",
    "rule" => array(
      "cosmos" => ""
    )
  ),
  "csscheck" => array(
    "icon" => "css",
    "title" => "CSSCheck",
    "rule" => array(
      "CSS_Validator" => "",
      "CSSCheck" => ""
    )
  ),
  "custo" => array(
    "icon" => "robot",
    "title" => "Custo",
    "rule" => array(
      "Custo[ /]?([0-9.]+)" => "\\1",
    )
  ),
  "d4x" => array(
    "icon" => "d4x",
    "title" => "Downloader for X",
    "rule" => array(
      "Downloader for X[ /]?([0-9.]+)" => "\\1"
    )
  ),
  "da" => array(
    "icon" => "da",
    "title" => "Download Accelerator",
    "rule" => array(
      "^DA[ /]?([0-9.]+)" => "\\1"
    )
  ),
  "discopump" => array(
    "icon" => "robot",
    "title" => "DISCo Pump",
    "rule" => array(
      "DISCo Pump[/ ]([0-9.]+)" => "\\1"
    )
  ),
  "doctorhtml" => array(
    "icon" => "robot",
    "title" => "DoctorHTML",
    "rule" => array(
      "Doctor[ \-]?HTML" => ""
    )
  ),
  "downloadninja" => array(
    "icon" => "robot",
    "title" => "Download Ninja",
    "rule" => array(
      "Download Ninja[ /]?([0-9.]+)" => "\\1"
    )
  ),
  "dsns" => array(
    "icon" => "robot",
    "title" => "DSNS Scanner",
    "rule" => array(
      "DSNS" => ""
    )
  ),
  "dtsagent" => array(
    "icon" => "robot",
    "title" => "DTS Agent",
    "rule" => array(
      "DTS Agent" => ""
    )
  ),
  "emailsiphon" => array(
    "icon" => "robot",
    "title" => "Email Siphon",
    "rule" => array(
      "Email[ \-]?Siphon" => ""
    )
  ),
  "estyle" => array(
    "icon" => "robot",
    "title" => "eStyle Search",
    "rule" => array(
      "eStyleSearch[ /]?([0-9.]+)" => "\\1"
    )
  ),
  "euroseek" => array(
    "icon" => "euroseek",
    "title" => "EuroSeek",
    "rule" => array(
      "Arachnoidea" => ""
    )
  ),
  "exabot" => array(
    "icon" => "exabot",
    "title" => "ExaBot",
    "rule" => array(
      "Exalead[ \-]?NG[ /]?([0-9.]+)" => "\\1",
      "Exalead[ \-]?NG" => ""
    )
  ),
  "exactseek" => array(
    "icon" => "robot",
    "title" => "ExactSeek",
    "rule" => array(
      "ExactSeek[ \-]?Crawler" => ""
    )
  ),
  "excite" => array(
    "icon" => "excite",
    "title" => "Excite",
    "rule" => array(
      "Architext[ \-]?Spider" => ""
    )
  ),
  "fast" => array(
    "icon" => "fast",
    "title" => "Fast",
    "rule" => array(
      "fast[ \-]?webcrawler[ /]?([0-9.]+)" => "\\1",
      "crawler@fast\.no" => ""
    )
  ),
  "favorg" => array(
    "icon" => "robot",
    "title" => "FavOrg",
    "rule" => array(
      "FavOrg" => ""
    )
  ),
  "fdse" => array(
    "icon" => "robot",
    "title" => "FDSE Robot",
    "rule" => array(
      "FDSE[ \-]?robot" => ""
    )
  ),
  "firefly" => array(
    "icon" => "firefly",
    "title" => "Firefly",
    "rule" => array(
      "Firefly" => ""
    )
  ),
  "flickbot" => array(
    "icon" => "robot",
    "title" => "FlickBot",
    "rule" => array(
      "FlickBot[ /]([0-9.]+)" => "\\1"
    )
  ),
  "friend" => array(
    "icon" => "friend",
    "title" => "Friend",
    "rule" => array(
      "www\.friend\.fr" => ""
    )
  ),
  "frontier" => array(
    "icon" => "robot",
    "title" => "Frontier",
    "rule" => array(
      "Frontier[ /]?([0-9.]+)" => "\\1"
    )
  ),
  "gaisbot" => array(
    "icon" => "robot",
    "title" => "Gaisbot",
    "rule" => array(
      "Gaisbot[ /]?([0-9.]+)" => "\\1"
    )
  ),
  "galaxy" => array(
    "icon" => "galaxy",
    "title" => "Galaxy",
    "rule" => array(
      "GalaxyBot[ /]?([0-9.]+)" => "\\1"
    )
  ),
  "genome" => array(
    "icon" => "robot",
    "title" => "Genome Machine",
    "rule" => array(
      "Genome[ \-]?Machine" => ""
    )
  ),
  "getright" => array(
    "icon" => "getright",
    "title" => "GetRight",
    "rule" => array(
      "GetRight[ /]?([0-9.]+)" => "\\1"
    )
  ),
  "getsmart" => array(
    "icon" => "getsmart",
    "title" => "GetSmart",
    "rule" => array(
      "GetSmart[ /]?([0-9.]+)" => "\\1"
    )
  ),
  "gigabot" => array(
    "icon" => "robot",
    "title" => "Gigablast",
    "rule" => array(
      "GigaBot" => ""
    )
  ),
  "girafabot" => array(
    "icon" => "girafa",
    "title" => "Girafa",
    "rule" => array(
      "Girafabot" => ""
    )
  ),
  "google" => array(
    "icon" => "google",
    "title" => "Google",
    "rule" => array (
      "googl(e|ebot)[ /]([0-9.]+)" => "\\2",
      "googl(e|ebot)[ /]" => ""
    )
  ),
  "grub" => array(
    "icon" => "grub",
    "title" => "Grub",
    "rule" => array(
      "grub[ \-]?client[ /\-]+([0-9.]+)" => "\\1"
    )
  ),
  "gulliver" => array(
    "icon" => "robot",
    "title" => "Gulliver",
    "rule" => array(
      "Gulliver" => ""
    )
  ),
  "gziptester" => array(
    "icon" => "robot",
    "title" => "Gzip Tester",
    "rule" => array(
      "gzip[ \-]?tester" => "",
      "GIDZip[ \-]?Test" => ""
    )
  ),
  "hatena" => array(
    "icon" => "hatena",
    "title" => "Hatena",
    "rule" => array(
      "Hatena Antenna[ /]?([0-9.]+)" => "\\1"
    )
  ),
  "heritrix" => array(
    "icon" => "heritrix",
    "title" => "Heritrix",
    "rule" => array(
      "heritrix[ /]?([0-9.]+)" => "\\1"
    )
  ),
  "htdig" => array(
    "icon" => "htdig",
    "title" => "ht://Dig",
    "rule" => array(
      "htdig[ /]?([0-9.]+)" => "\\1"
    )
  ),
  "httperf" => array(
    "icon" => "robot",
    "title" => "HTTPerf",
    "rule" => array(
      "httperf[ /]?([0-9.]+)" => "\\1"
    )
  ),
  "httrack" => array(
    "icon" => "robot",
    "title" => "HTTrack",
    "rule" => array(
      "HTTrack[ /]?([0-9.]+)" => "\\1"
    )
  ),
  "ilse" => array(
    "icon" => "ilse",
    "title" => "Ilse",
    "rule" => array(
      "INGRID[ /]?([0-9.]+)" => "\\1"
    )
  ),
  "iltrovatore" => array(
    "icon" => "iltrovatore",
    "title" => "IlTrovatore",
    "rule" => array(
      "iltrovatore-setaccio[ /]?([0-9.]+)" => "\\1",
      "Iltrovatore-Setaccio" => ""
    )
  ),
  "indylibrary" => array(
    "icon" => "robot",
    "title" => "Indy Library",
    "rule" => array(
      "Indy[ \-]?Library" => ""
    )
  ),
  "infoart" => array(
    "icon" => "robot",
    "title" => "InfoArt",
    "rule" => array(
      "InfoArt crawler" => ""
    )
  ),
  "infoseek" => array(
    "icon" => "infoseek",
    "title" => "Infoseek",
    "rule" => array(
      "SideWinder[ /]?([0-9a-z.]+)" => "\\1",
      "Infoseek" => ""
    )
  ),
  "inktomi" => array(
    "icon" => "inktomi",
    "title" => "Inktomi",
    "rule" => array(
      "slurp@inktomi\.com" => ""
    )
  ),
  "jigsaw" => array(
    "icon" => "jigsaw",
    "title" => "Jigsaw",
    "rule" => array(
      "Jigsaw[ /]?([0-9.]+)" => "\\1",
    )
  ),
  "kinja" => array(
    "icon" => "kinja",
    "title" => "Kinja",
    "rule" => array(
      "kinjabot[ /]?([0-9.]+)" => "\\1",
    )
  ),
  "lachesis" => array(
    "icon" => "robot",
    "title" => "Lachesis",
    "rule" => array(
      "lachesis" => ""
    )
  ),
  "larbin" => array(
    "icon" => "robot",
    "title" => "Larbin",
    "rule" => array(
      "larbin[/_ ]([0-9.])" => "\\1"
    )
  ),
  "linkcheck" => array(
    "icon" => "linkcheck",
    "title" => "Linkcheck",
    "rule" => array(
      "Link[ \-]?Chec(k|ker)" => "",
      "Link[ \-]?Valet" => "",
      "link[ \-]?validator" => "",
    )
  ),
  "linkssql" => array(
    "icon" => "robot",
    "title" => "Links SQL",
    "rule" => array(
      "links sql" => ""
    )
  ),
  "linksweeper" => array(
    "icon" => "robot",
    "title" => "Link Sweeper",
    "rule" => array(
      "LinkSweeper[ /]?([0-9.]+)" => "\\1"
    )
  ),
  "look" => array(
    "icon" => "look",
    "title" => "Look",
    "rule" => array(
      "www\.look\.com" => ""
    )
  ),
  "loop" => array(
    "icon" => "loop",
    "title" => "LOOP",
    "rule" => array(
      "NetResearchServer[ /]?([0-9.]+)" => "\\1"
    )
  ),
  "looksmart" => array(
    "icon" => "looksmart",
    "title" => "Looksmart",
    "rule" => array(
      "looksmart-sv-fw" => ""
    )
  ),
  "lotkyll" => array(
    "icon" => "robot",
    "title" => "Lotkyll",
    "rule" => array(
      "Lotkyll" => ""
    )
  ),
  "lwp" => array(
    "icon" => "robot",
    "title" => "lwp",
    "rule" => array(
      "lwp(-trivial|::simple)[ /]?([0-9.]+)" => "\\2"
    )
  ),
  "magpierss" => array(
    "icon" => "robot",
    "title" => "MagpieRSS",
    "rule" => array(
      "MagpieRSS" => ""
    )
  ),
  "mailsweeper" => array(
    "icon" => "robot",
    "title" => "Mail Sweeper",
    "rule" => array(
      "Mail[ \-]?Sweeper" => ""
    )
  ),
  "marvin" => array(
    "icon" => "robot",
    "title" => "Marvin",
    "rule" => array(
      "Marvin" => ""
    )
  ),
  "mercator" => array(
    "icon" => "robot",
    "title" => "Mercator",
    "rule" => array(
      "Mercator" => ""
    )
  ),
  "metager" => array(
    "icon" => "metager",
    "title" => "MetaGer",
    "rule" => array(
      "MetaGer" => ""
    )
  ),
  "mirago" => array(
    "icon" => "mirago",
    "title" => "Mirago",
    "rule" => array(
      "Mirago" => ""
    )
  ),
  "momspider" => array(
    "icon" => "robot",
    "title" => "MOM Spider",
    "rule" => array(
      "MOMspider[ /]?([0-9.]+)" => "\\1"
    )
  ),
  "movabletype" => array(
    "icon" => "movabletype",
    "title" => "Movable Type",
    "rule" => array(
      "MovableType[ /]?([0-9.]+)" => "\\1"
    )
  ),
  "mozdex" => array(
    "icon" => "mozdex",
    "title" => "MozDex",
    "rule" => array(
      "mozDex[ /]?([a-z0-9.\-]+)" => "\\1"
    )
  ),
  "msnbot" => array(
    "icon" => "msn",
    "title" => "MSN",
    "rule" => array(
      "MSNBOT[ /]?([0-9.]+)" => "\\1"
    )
  ),
  "msproxy" => array(
    "icon" => "robot",
    "title" => "MSProxy",
    "rule" => array(
      "MSProxy[ /]?([0-9.]+)" => "\\1"
    )
  ),
  "mswebdav" => array(
    "icon" => "robot",
    "title" => "MS-WebDAV",
    "rule" => array(
      "Microsoft[ \-]?WebDAV[ \-]?MiniRedir" => ""
    )
  ),
  "nameprotect" => array(
    "icon" => "nameprotect",
    "title" => "Name Protect",
    "rule" => array(
      "NPBot" => "",
    )
  ),
  "nationaldirectory" => array(
    "icon" => "robot",
    "title" => "National Directory",
    "rule" => array(
      "NationalDirectory-WebSpider[ /]?([0-9.]+)" => "\\1",
    )
  ),
  "naverbot" => array(
    "icon" => "naverbot",
    "title" => "Naver",
    "rule" => array(
      "NaverBot([_\-]dloader)?[/ \-]?([0-9.]+)" => "\\2",
      "NaverBot" => "",
    )
  ),
  "netants" => array(
    "icon" => "netants",
    "title" => "NetAnts",
    "rule" => array(
      "NetAnts[ /]?([0-9.]+)" => "\\1"
    )
  ),
  "netcraft" => array(
    "icon" => "netcraft",
    "title" => "Netcraft",
    "rule" => array(
      "netcraft" => ""
    )
  ),
  "netmechanic" => array(
    "icon" => "netmechanic",
    "title" => "NetMechanic",
    "rule" => array(
      "NetMechanic[ /V]+([0-9.]+)" => "\\1",
    )
  ),
  "netoskop" => array(
    "icon" => "robot",
    "title" => "Netoskop",
    "rule" => array(
      "netoskop" => ""
    )
  ),
  "nutchorg" => array(
    "icon" => "robot",
    "title" => "NutchOrg",
    "rule" => array(
      "NutchOrg[ /]([0-9.]+)" => "\\1",
      "Nutch(CVS)?[ /]([0-9.]+)" => "\\2"
    )
  ),
  "obidosbot" => array(
    "icon" => "robot",
    "title" => "ObidosBot",
    "rule" => array(
      "obidos[ \-]?bot" => ""
    )
  ),
  "objectssearch" => array(
    "icon" => "robot",
    "title" => "Objects Search",
    "rule" => array(
      "ObjectsSearch[ /]?([0-9.]+)" => "\\1"
    )
  ),
  "openfind" => array(
    "icon" => "openfind",
    "title" => "Openfind",
    "rule" => array(
      "openbot[ /]?([0-9.]+)" => "\\1"
    )
  ),
  "organica" => array(
    "icon" => "robot",
    "title" => "Organica",
    "rule" => array(
      "crawler@organica\.us" => ""
    )
  ),
  "overture" => array(
    "icon" => "overture",
    "title" => "Overture",
    "rule" => array(
      "Overture[ \-]?WebCrawler" => ""
    )
  ),
  "php" => array(
    "icon" => "php",
    "title" => "PHP",
    "rule" => array(
      "PHP[ /]?([0-9.]+)" => "\\1",
    )
  ),
  "plsearch" => array(
    "icon" => "plsearch",
    "title" => "PlanetSearch",
    "rule" => array(
      "fido[ /]?([0-9.]+) Harvest" => "PlanetSearch"
    )
  ),
  "poodle" => array(
    "icon" => "robot",
    "title" => "Poodle predictor",
    "rule" => array(
      "Poodle[ \-]?predictor" => ""
    )
  ),
  "pompos" => array(
    "icon" => "pompos",
    "title" => "Pompos",
    "rule" => array(
      "Pompos[ /]?([0-9.]+)" => "\\1",
    )
  ),
  "popdex" => array(
    "icon" => "robot",
    "title" => "Popdexter",
    "rule" => array(
      "Popdexter" => ""
    )
  ),
  "powermarks" => array(
    "icon" => "robot",
    "title" => "Powermarks",
    "rule" => array(
      "Powermarks[ /]?([0-9.]+)" => "\\1",
    )
  ),
  "proxycache" => array(
    "icon" => "robot",
    "title" => "Proxy Cache",
    "rule" => array(
      "^Mozilla/[0-9.]+ \(compatible\;\)$" => ""
    )
  ),
  "proxyhunter" => array(
    "icon" => "robot",
    "title" => "ProxyHunter",
    "rule" => array(
      "ProxyHunter" => ""
    )
  ),
  "psbot" => array(
    "icon" => "robot",
    "title" => "PicSearch",
    "rule" => array(
      "psbot" => ""
    )
  ),
  "pxys" => array(
    "icon" => "robot",
    "title" => "PXYS",
    "rule" => array(
      "pxys" => ""
    )
  ),
  "pythonurl" => array(
    "icon" => "robot",
    "title" => "Python-url",
    "rule" => array(
      "Python[ \-]?urllib" => ""
    )
  ),
  "quepasa" => array(
    "icon" => "quepasa",
    "title" => "Quepasa",
    "rule" => array(
      "Quepasa[ \-]?Creep" => ""
    )
  ),
  "rambler" => array(
    "icon" => "rambler",
    "title" => "Rambler",
    "rule" => array(
      "StackRambler[ /]?([0-9.]+)" => "\\1"
    )
  ),
  "robozilla" => array(
    "icon" => "robot",
    "title" => "Robozilla",
    "rule" => array(
      "Robozilla" => ""
    )
  ),
  "scrubby" => array(
    "icon" => "scrubby",
    "title" => "Scrubby",
    "rule" => array(
      "Scrubby[ /]?([0-9.]+)" => "\\1"
    )
  ),
  "searchch" => array(
    "icon" => "robot",
    "title" => "Search.ch",
    "rule" => array(
      "search\.ch[ /]?V?([0-9.]+)" => "\\1"
    )
  ),
  "searchthruus" => array(
    "icon" => "robot",
    "title" => "SearchThruUs",
    "rule" => array(
      "www\.unitek-systems\.co\.uk[ /]?([0-9.]+)" => "\\1"
    )
  ),
  "semanticdiscovery" => array(
    "icon" => "robot",
    "title" => "Semantic Discovery",
    "rule" => array(
      "semanticdiscovery[ /]?([0-9.]+)" => "\\1"
    )
  ),
  "shareware" => array(
    "icon" => "robot",
    "title" => "Shareware",
    "rule" => array(
      "Program[ \-]?Shareware[ /]?([0-9.]+)" => "\\1"
    )
  ),
  "sherlockspider" => array(
    "icon" => "robot",
    "title" => "Sherlock Spider",
    "rule" => 
    array(
      "sherlock_spider" => ""
    )
  ),
  "singingfish" => array(
    "icon" => "singingfish",
    "title" => "SingingFish",
    "rule" => array(
      "asterias[ /]?([0-9.]+)" => "\\1",
      "asterias" => ""
    )
  ),
  "sirobot" => array(
    "icon" => "robot",
    "title" => "SiroBot",
    "rule" => array(
      "sirobot" => ""
    )
  ),
  "steeler" => array(
    "icon" => "robot",
    "title" => "Steeler",
    "rule" => array(
      "Steeler[ /]?([0-9.]+)" => "\\1"
    )
  ),
  "surfcontrol" => array(
    "icon" => "robot",
    "title" => "SurfControl",
    "rule" => array(
      "SurfControl" => ""
    )
  ),
  "surveybot" => array(
    "icon" => "robot",
    "title" => "Whois Survey",
    "rule" => array(
      "SurveyBot[ /]?([0-9.]+)" => "\\1"
    )
  ),
  "szukacz" => array(
    "icon" => "szukacz",
    "title" => "Szukacz",
    "rule" => array(
      "Szukacz[ /]?([0-9.]+)" => "\\1",
    )
  ),
  "technorati" => array(
    "icon" => "technorati",
    "title" => "Technorati",
    "rule" => array(
      "Technoratibot[ /]?([0-9.]+)" => "\\1"
    )
  ),
  "teleport" => array(
    "icon" => "teleport",
    "title" => "Teleport",
    "rule" => array(
      "Teleport[ \-]?Pro" => ""
    )
  ),
  "thunderstone" => array(
    "icon" => "thunderstone",
    "title" => "Thunderstone",
    "rule" => array(
      "T-H-U-N-D-E-R-S-T-O-N-E" => ""
    )
  ),
  "timbobot" => array(
    "icon" => "robot",
    "title" => "timboBot",
    "rule" => array(
      "timboBot" => ""
    )
  ),
  "turnitin" => array(
    "icon" => "turnitin",
    "title" => "Turnitin",
    "rule" => array(
      "TurnitinBot[ /]?([0-9.]+)" => "\\1",
    )
  ),
  "tutorgig" => array(
    "icon" => "robot",
    "title" => "TutorGig",
    "rule" => array(
      "Tutorial Crawler[ /]?([0-9.]+)" => "\\1",
    )
  ),
  "typepad" => array(
    "icon" => "typepad",
    "title" => "TypePad",
    "rule" => array(
      "TypePad/([0-9a-z.]+)" => "\\1"
    )
  ),
  "udmsearch" => array(
    "icon" => "robot",
    "title" => "UdmSearch",
    "rule" => array(
      "UdmSearch[/ ]([0-9.]+)" => "\\1"
    )
  ),
  "urlcontr" => array(
    "icon" => "robot",
    "title" => "MS URL Control",
    "rule" => array(
      "Microsoft URL[ \-]?Control" => "\\1"
    )
  ),
  "ultraseek" => array(
    "icon" => "robot",
    "title" => "Ultraseek",
    "rule" => array(
      "Ultraseek" => ""
    )
  ),
  "vagabondo" => array(
    "icon" => "wiseguys",
    "title" => "WiseGuys",
    "rule" => array(
      "Vagabondo[ /]?([0-9.]+)" => "\\1",
    )
  ),
  "validator" => array(
    "icon" => "validator",
    "title" => "Validator",
    "rule" => array(
      "Validator[ /]?([0-9.]+)" => "\\1",
    )
  ),
  "vindex" => array(
    "icon" => "vindex",
    "title" => "Vindex",
    "rule" => array(
      "Vindex[ /]?([0-9.]+)" => "\\1",
    )
  ),
  "voila" => array(
    "icon" => "voila",
    "title" => "Voila",
    "rule" => array(
      "VoilaBot[ /]?[a-z ]*([0-9.]+)" => "\\1",
    )
  ),
  "watson" => array(
    "icon" => "addy",
    "title" => "Dr.Watson",
    "rule" => array(
      "Watson[ /]?([0-9.]+)" => "\\1",
      "watson\.addy\.com" => "",
    )
  ),
  "waypath" => array(
    "icon" => "robot",
    "title" => "Waypath Scout",
    "rule" => array(
      "Waypath[ \-]?Scout" => ""
    )
  ),
  "webcollage" => array(
    "icon" => "robot",
    "title" => "Webcollage",
    "rule" => array(
      "webcollage" => ""
    )
  ),
  "webcopier" => array(
    "icon" => "robot",
    "title" => "WebCopier",
    "rule" => array(
      "WebCopier[/ ]v?([0-9.]+)" => "\\1"
    )
  ),
  "webpix" => array(
    "icon" => "webpix",
    "title" => "WebPix",
    "rule" => array(
      "WebPix[/ ]([0-9.]+)" => "\\1"
    )
  ),
  "websense" => array(
    "icon" => "robot",
    "title" => "Websense",
    "rule" => array(
      "Sqworm[/ ]([0-9.]+)" => "\\1",
      "websense" => ""
    )
  ),
  "websquash" => array(
    "icon" => "websquash",
    "title" => "Websquash",
    "rule" => array(
      "websquash\.com" => "",
      "Website[ \-]?Monitor" => ""
    )
  ),
  "webstripper" => array(
    "icon" => "robot",
    "title" => "WebStripper",
    "rule" => array(
      "WebStripper[ /]?([0-9.]+)" => "\\1",
    )
  ),
  "webzip" => array(
    "icon" => "webzip",
    "title" => "WebZIP",
    "rule" => array(
      "Web[ \-]?ZIP[ /]?([0-9.]+)" => "\\1",
    )
  ),
  "wget" => array(
    "icon" => "wget",
    "title" => "Wget",
    "rule" => 
    array(
      "Wget[ /]?([0-9.]+)" => "\\1",
    )
  ),
  "wmp" => array(
    "icon" => "robot",
    "title" => "WMP",
    "rule" => array(
      "WMP" => ""
    )
  ),
  "wotbox" => array(
    "icon" => "wotbox",
    "title" => "Wotbox",
    "rule" => 
    array(
      "Wotbox[ /]?[a-z]*([0-9.]+)" => "\\1",
    )
  ),
  "wwgrapevine" => array(
    "icon" => "wwgrapevine",
    "title" => "WWgrapevine",
    "rule" => 
    array(
      "wwgrapevine[ /]?([0-9.]+)" => "\\1",
    )
  ),
  "xenu" => array(
    "icon" => "robot",
    "title" => "Xenu Link Sleuth",
    "rule" => array(
      "Xenu[ \-]?Link[ \-]?Sleuth" => ""
    )
  ),
  "yahoo" => array(
    "icon" => "yahoo",
    "title" => "Yahoo",
    "rule" => array(
      "Yahoo! Slurp;" => "",
      "^Yahoo-" => ""
    )
  ),
  "yandex" => array(
    "icon" => "yandex",
    "title" => "Yandex",
    "rule" => array(
      "Yandex[/ ]([0-9.]+)" => "\\1"
    )
  ),
  "zao" => array(
    "icon" => "robot",
    "title" => "Zao",
    "rule" => array(
      "Zao[ /]?([0-9.]+)" => "\\1"
    )
  ),
  "zealbot" => array(
    "icon" => "zeal",
    "title" => "ZealBot",
    "rule" => array(
      "Zealbot[ /]?([0-9.]+)" => "\\1"
    )
  ),
  "zeus" => array(
    "icon" => "robot",
    "title" => "Zeus",
    "rule" => array(
      "Zeus" => ""
    )
  ),
  "zyborg" => array(
    "icon" => "zyborg",
    "title" => "WiseNutBot",
    "rule" => array(
      "Zyborg[ /]?([0-9.]+)" => "\\1",
    )
  ),
//sebbi.de stuff
  "technorati2" => array(
    "icon" => "technorati",
    "title" => "Technorati FP",
    "rule" => array(
      "UniversalFeedParser/([a-z0-9.-]+)" => "\\1"
    )
  ),
  "pubsub" => array(
    "icon" => "pubsub",
    "title" => "PubSub.com",
    "rule" => array(
      "PubSub.com" => ""
    )
  ),
  "syndic8" => array(
    "icon" => "syndic8",
    "title" => "Syndic8",
    "rule" => array(
      "Syndic8/([0-9][0-9.]+)" => "\\1"
    )
  ),
  "blogsnowbot" => array(
    "icon" => "robot",
    "title" => "Blogsnow",
    "rule" => array(
      "blogsnowbot http://www.blogsnow.com/bot.html" => ""
    )
  ),
  "blogg.de" => array(
    "icon" => "robot",
    "title" => "blogg.de",
    "rule" => array(
      "blogg.de-Crawler" => ""
    )
  ),
  "findlinks" => array(
    "icon" => "robot",
    "title" => "findlinks",
    "rule" => array(
      "findlinks/([0-9][0-9.]+)" => "\\1"
    )
  ),
  "nitle" => array(
    "icon" => "robot",
    "title" => "NITLE Blog Spider",
    "rule" => array(
      "NITLE Blog Spider/([0-9][0-9.]+)" => "\\1"
    )
  ),
  "feedster" => array(
    "icon" => "robot",
    "title" => "Feedster Crawler",
    "rule" => array(
      "Feedster Crawler/([0-9][0-9.]+)" => "\\1"
    )
  ),
  "lmspider" => array(
    "icon" => "robot",
    "title" => "Lmspider",
    "rule" => array(
      "lmspider lmspider@scansoft.com" => ""
    )
  ),

// generic stuff
  "httpclient" => array(
    "icon" => "robot",
    "title" => "HTTPClient",
    "rule" => array(
      "HTTP[ \-]?Client" => ""
    )
  ),
// Catch up for things we don't know by now
  "robot" => array(
    "icon" => "robot",
    "title" => "Robot",
    "rule" => array(
      "robot" => "",
      "crawler" => "",
      "spider" => ""
    )
  )
);

$os_array = array(
  "aix"=> array(
    "icon"=> "aix",
    "title" => "AIX",
    "rule" => array(
      "aix" => ""
    )
  ),
  "atheos" => array(
    "icon" => "atheos",
    "title" => "AtheOS",
    "rule" => array(
      "atheos" => ""
    )
  ),
  "amiga" => array(
    "icon" => "amiga",
    "title" => "AmigaOS",
    "rule" => array(
      "Amiga[ ]?OS[ /]([0-9.]+)" => "\\1",
      "amiga" => ""
    )
  ),
  "beos" => array(
    "icon" => "be",
    "title" => "BeOS",
    "rule" => array(
      "beos[ a-z]*([0-9.]+)" => "\\1",
      "beos" => ""
    )
  ),
  "darwin" => array(
    "icon" => "darwin",
    "title" => "Darwin",
    "rule" => array(
      "Darwin[ ]?([0-9.]+)" => "\\1",
      "Darwin" => ""
    )
  ),
  "digital" => array(
    "icon" => "digital",
    "title" => "Digital",
    "rule" => array(
      "OSF([0-9.]+)[ ]?V4" => "\\1"
    )
  ),
  "freebsd" => array(
    "icon" => "freebsd",
    "title" => "FreeBSD",
    "rule" => array(
     "free[ \-]?bsd[ /]([a-z0-9.]+)" => "\\1",
     "free[ \-]?bsd" => ""
    )
  ),
  "hpux" => array(
    "icon" => "hp",
    "title" => "HPUX",
    "rule" => array(
      "hp[ \-]?ux[ /]([a-z0-9.]+)" => "\\1",
    )
  ),
  "irix" => array(
    "icon" => "irix",
    "title" => "IRIX",
    "rule" => array(
      "irix[0-9]*[ /]([0-9.]+)" => "\\1", 
      "irix" => ""
    )
  ),
  "linux" => array(
    "icon" => "linux",
    "title" => "Linux",
    "rule" => array(
      "mdk for ([0-9.]+)" => "MDK \\1",
      "linux[ /\-]([a-z0-9.]+)" => "\\1",
      "linux" => ""
    )
  ),
  "macosx" => array(
    "icon" => "macosx",
    "title" => "MacOS X",
    "rule" => array(
      "Mac[ ]?OS[ ]?X" => ""
    )
  ),
  "macppc" => array(
    "icon" => "macppc",
    "title" => "MacOS PPC",
    "rule" => array(
      "Mac_PowerPC" => "",
      "Macintosh(.+)PPC" => ""
    )
  ),
  "netbsd" => array(
    "icon" => "netbsd",
    "title" => "NetBSD",
    "rule" => array(
      "net[ \-]?bsd[ /]([a-z0-9.]+)" => "\\1",
      "net[ \-]?bsd" => ""
    )
  ),
  "os2" => array(
    "icon" => "os2",
    "title" => "OS/2 Warp",
    "rule" => array(
      "warp[ /]?([0-9.]+)" => "\\1",
      "os[ /]?2" => "",
    )
  ),
  "openbsd" => array(
    "icon" => "openbsd",
    "title" => "OpenBSD",
    "rule" => array(
      "open[ \-]?bsd[ /]([a-z0-9.]+)" => "\\1",
      "open[ \-]?bsd" => ""
    )
  ),
  "openvms" => array(
    "icon" => "openvms",
    "title" => "OpenVMS",
    "rule" => array(
      "Open[ \-]?VMS[ /]([a-z0-9.]+)" => "\\1",
      "Open[ \-]?VMS" => ""
    )
  ),
  "palm" => array(
    "icon" => "palm",
    "title" => "PalmOS",
    "rule" => array(
      "Palm[ \-]?OS[ /]?([0-9.]+)" => "\\1",
      "Palm[ \-]?OS" => ""
    )
  ),
  "photon" => array(
    "icon" => "qnx",
    "title" => "QNX Photon",
    "rule" => array(
      "photon" => ""
    )
  ),
  "sun" => array(
    "icon" => "sun",
    "title" => "SunOS",
    "rule" => array(
      "sun[ \-]?os[ /]?([0-9.]+)" => "\\1",
      "sun[ \-]?os" => ""
    )
  ),
  "symbian" => array(
    "icon"  => "symbian",
    "title" => "Symbian OS",
    "rule"  => array(
      "Symbian" => ""
    )
  ),
  "tru64" => array(
    "icon" => "tru64",
    "title" => "Tru64",
    "rule" => array(
      "OSF([0-9.]+)[ ]?V5" => "\\1"
    )
  ),
  "unixware" => array(
    "icon" => "sco",
    "title" => "UnixWare",
    "rule" => array(
      "unixware[ /]?([0-9.]+)" => "\\1",
      "unixware" => ""
    )
  ),
  "windows2003" => array(
    "icon" => "windowsxp",
    "title" => "Windows 2003",
    "rule" => array(
      "Wi(n|ndows)[ \-]?2003" => "",
      "wi(n|ndows)[ \-]?nt[ /]?5\.2" => ""
    )
  ),
  "windows2k" => array(
    "icon" => "windows",
    "title" => "Windows 2000",
    "rule" => array(
      "wi(n|ndows)[ \-]?nt[ /]?5\.0" => "",
      "wi(n|ndows)[ \-]?2000" => ""
    )
  ),
  "windows95" => array(
    "icon" => "windows",
    "title" => "Windows 95",
    "rule" => array(
      "wi(n|ndows)[ \-]?95" => "",
    )
  ),
  "windowsce" => array(
    "icon" => "windows",
    "title" => "Windows CE",
    "rule" => array(
      "wi(n|ndows)[ \-]?ce" => ""
    )
  ),
  "windowsme" => array(
    "icon" => "windows",
    "title" => "Windows ME",
    "rule" => array(
      "win 9x 4\.90" => "",
      "wi(n|ndows)[ \-]?me" => "",
    )
  ),
  "windowsxp" => array(
    "icon" => "windowsxp",
    "title" => "Windows XP",
    "rule" => array(
      "Windows XP" => "",
      "wi(n|ndows)[ \-]?nt[ /]?5\.1" => ""
    )
  ),
// The following ones are catch ups, they got to stay here.
  "bsd" => array(
    "icon" => "bsd",
    "title" => "BSD",
    "rule" => array(
      "bsd" => ""
    )
  ),
  "mac" => array(
    "icon" => "mac",
    "title" => "MacOS",
    "rule" => array(
      "mac[^h]" => ""
    )
  ),
  "windowsnt" => array(
    "icon" => "windows",
    "title" => "Windows NT",
    "rule" => array(
      "wi(n|ndows)[ \-]?nt[ /]?([0-4][0-9.]+)" => "\\2",
      "wi(n|ndows)[ \-]?nt" => "",
    )
  ),
  "windows98" => array(
    "icon" => "windows",
    "title" => "Windows 98",
    "rule" => array(
      "wi(n|ndows)[ \-]?98" => "",
    )
  ),
  "windows" => array(
    "icon" => "windows",
    "title" => "Windows",
    "rule" => array(
      "wi(n|n32|ndows)" => ""
    )
  ),
// things we don't know by now
  "other" => array(
    "icon" => "question",
    "title" => "other",
    "rule" => array(
      ".+" => ""
    )
  )
);
?>