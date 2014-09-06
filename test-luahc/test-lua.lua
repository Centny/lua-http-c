package.cpath = package.cpath .. ";?.dylib;/usr/local/lib/lua/5.1/?.dylib"
require("libluahc")
curl_g("http://www.baidu.com")
