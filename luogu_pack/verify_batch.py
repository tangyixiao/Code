import argparse,csv,subprocess,tempfile
from pathlib import Path

R=Path(__file__).resolve().parent.parent

def run(a,**k):
 return subprocess.run(a,check=True,timeout=k.pop('timeout',30),**k)

def main():
 p=argparse.ArgumentParser();p.add_argument('batch');p.add_argument('--rounds',type=int,default=1000);a=p.parse_args()
 with (R/'luogu_pack/manifest.tsv').open(encoding='utf-8') as f:rows=[x for x in csv.DictReader(f,delimiter='\t') if x['batch']==a.batch]
 with tempfile.TemporaryDirectory() as d:
  d=Path(d)
  for x in rows:
   b=x['base'];parts=sorted(x for x in R.iterdir() if x.name.startswith(b+' 部分分') and x.suffix=='.cpp')
   fs=[R/(b+s) for s in ('.cpp',' 数据生成.cpp',' 暴力.cpp',' 对拍.cpp')]+parts
   for i,f in enumerate(fs):run(['g++','-std=c++14','-O2',str(f),'-o',str(d/f'c{i}')],stdout=subprocess.PIPE,stderr=subprocess.PIPE,timeout=60)
   main=d/'main';run(['g++','-std=c++14','-O2',str(R/(b+'.cpp')),'-o',str(main)],stdout=subprocess.PIPE,stderr=subprocess.PIPE,timeout=60)
   for f in sorted((R/'cph'/b).glob('*.in')):
    o=run([str(main)],input=f.read_bytes(),stdout=subprocess.PIPE,stderr=subprocess.PIPE).stdout
    if o.split()!=f.with_suffix('.ans').read_bytes().split():raise SystemExit(f'WA {f}')
   stress=d/'stress';run(['g++','-std=c++14','-O2',str(R/(b+' 对拍.cpp')),'-o',str(stress)],stdout=subprocess.PIPE,stderr=subprocess.PIPE,timeout=60)
   o=run([str(stress),str(a.rounds),'1'],stdout=subprocess.PIPE,stderr=subprocess.PIPE,timeout=60).stdout.split()
   if o!=[b'OK']:raise SystemExit(f'STRESS {b}: {o!r}')
   gen=d/'gen';run(['g++','-std=c++14','-O2',str(R/(b+' 数据生成.cpp')),'-o',str(gen)],stdout=subprocess.PIPE,stderr=subprocess.PIPE,timeout=60)
   z=run([str(gen),'7','20'],stdout=subprocess.PIPE,stderr=subprocess.PIPE).stdout
   run([str(main)],input=z,stdout=subprocess.PIPE,stderr=subprocess.PIPE,timeout=60)
   print('PASS',b,flush=True)

if __name__=='__main__':main()
