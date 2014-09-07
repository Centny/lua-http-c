lua-http-c
===

the lua module for http get/post(by libcurl).
## Pre Requirement
* libcurl
* lua>=5.1

## Getting Started

install this plugin with this command:

```bash
$ git clone https://github.com/Centny/lua-http-c
$ cd lua-http-c/libluahc
$ export LUA_LIBDIR=/usr/local/lib/lua/5.1
$ make -f MakefileLua install
```

## Example

```lua
require("luahc")
res=luahc.get("http://www.xxx.com")
--res=luahc.post("http://www.xxx.com")
for key, val in pairs(res) do
 if type(val)=="table" then
  print(key..":")
  for hk, hv in pairs(val) do
  	print("  "..hk..":"..hv);
  end
 elseif key~="data" then
  print(key..":"..val);
 end
end
print(res.msg)
```

## Document
return table struct

```lua
{
 lcode=0,--lua execute return code.
 ccode=0,--CURL execute return code.
 rcode=0,--HTTP response code.
 ctype="text/html",--HTTP response Content-Type.
 clen=100,--HTTP response Content-Length.
 data="data",--HTTP response data.
 header={--HTTP response HEADER.
   key="value"
  }
}
```

#### luahc.get
```lua
res=luahc.get(url,{
 header1=1,header2="abc"
})
``

#### luahc.post
```lua
res=luahc.post(url,{
 key1=1,key2="abc"
 },{
 header1=1,header2="abc"
})
```
