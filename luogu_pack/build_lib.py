import html,json,re
from pathlib import Path
R=Path(__file__).resolve().parent.parent
def q(p):
 s=Path('/tmp/'+p+'.json').read_text();x=re.search(r'<script id="lentille-context" type="application/json">(.*?)</script>',s,re.S)
 return json.loads(html.unescape(x.group(1)))['data']['problem']
def w(n,s):
 (R/n).parent.mkdir(parents=True,exist_ok=True);(R/n).write_text(re.sub(r'[ \t]+(?=\n|$)','',s.strip())+'\n')
def add(p,b,sol,codes,parts=(),extra=()):
 x=q(p);z=x['contenu'];e=x.get('translations',{}).get('en',{});g=lambda y,k:y.get(k,'').strip()
 s=f"# {p} {z['name']}\n\n## 中文题面\n\n### 题目描述\n\n{g(z,'description')}\n\n### 输入格式\n\n{g(z,'formatI')}\n\n### 输出格式\n\n{g(z,'formatO')}"
 for i,a in enumerate(x.get('samples',[]),1):s+=f"\n\n### 样例 {i}\n\n```text\n{a[0].rstrip()}\n```\n\n```text\n{a[1].rstrip()}\n```"
 s+=f"\n\n### 说明与限制\n\n{g(z,'hint')}\n\n## English Statement\n\n### Description\n\n{g(e,'description')}\n\n### Input\n\n{g(e,'formatI')}\n\n### Output\n\n{g(e,'formatO')}\n\n### Constraints\n\n{g(e,'hint')}"
 w(b+'.md',s);w(b+' 题解.md',f'# {b} 题解\n\n{sol}')
 for k,v in codes.items():w(b+k,v)
 for i,v in enumerate(parts,1):w(f'{b} 部分分{i}.cpp',v)
 d=R/'cph'/b;d.mkdir(parents=True,exist_ok=True)
 for i,a in enumerate(x.get('samples',[]),1):w(str((d/f'{b}_{i}.in').relative_to(R)),a[0]);w(str((d/f'{b}_{i}.ans').relative_to(R)),a[1])
 k=len(x.get('samples',[]))
 for a,o in extra:k+=1;w(str((d/f'{b}_{k}.in').relative_to(R)),a);w(str((d/f'{b}_{k}.ans').relative_to(R)),o)
