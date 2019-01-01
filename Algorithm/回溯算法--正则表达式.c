class Pattern:
  matched = False
  def __init__(self,pattern, plen):
    self.pattern = pattern # 正则表达式
    self.plen = plen  #正则表达式长度
    

  def rmatch(self,ti,pj,text,tlen):
    if self.matched: #如果已经匹配了，就不要继续递归了
         return 
    if pj == self.plen: # 正则表达式到结尾了
      if ti == tlen:  # 文本串也到结尾了
        self.matched = True
      return

    if self.pattern[pj] == '*':  # * 匹配任意个字符
      for k in range(0,tlen-ti+1):
        self.rmatch(ti+k, pj+1, text,tlen)
      
    elif self.pattern[pj] == '?': # ? 匹配 0 个或者 1 个字符
      self.rmatch(ti, pj+1, text, tlen)
      self.rmatch(ti+1, pj+1, text, tlen)

    elif ti < tlen and self.pattern[pj] == text[ti]: #纯字符匹配才行
      self.rmatch(ti+1, pj+1, text, tlen)

  def match(self,text,tlen): #文本串及长度
    self.matched = False;
    self.rmatch(0, 0, text, tlen);
    return self.matched;

pattern = Pattern("yu*uo?ui",8)
result = pattern.match("yugabcdefuohui",14)
if result:
    print("匹配成功！")
else:
    print("匹配失败！")
