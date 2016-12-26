error_reporting ( 0 );
$uri = $_SERVER ["REQUEST_URI"];
preg_match ( "/baidu.php\/(.+)\/(.+)\//", $uri, $code );
$a = $code [1];

$b = $code [2];

$url = "http://pan.baidu.com/share/link?shareid=$a&uk=$b";

$data = file_get_contents ( $url, false, $context );
preg_match ( "/(http:\/\/d.pcs.baidu.com.*?)\"/", $data, $data );
$myurl = str_replace ( '&', '&', $data [1] );
if ($myurl) {
header ( 'Content-Type:application/force-download' );
header ( "Location:" . $myurl );
die ();
} else
echo "参数错误";
?>