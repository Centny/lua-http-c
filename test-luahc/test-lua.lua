require("luahc")
res=luahc.get("http://www.baidu.com")
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
