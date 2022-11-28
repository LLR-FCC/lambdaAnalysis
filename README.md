cd /afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses
source setup.sh

cd /afs/cern.ch/user/n/niharrin/work/public/MA/FCCeePhysicsPerformance/case-studies/higgs/dataframe
source localSetup.sh

cd /afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/combination

cd /afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/ee_nuenuebb_exclusive/365



//
//          P L O T T I N G
//
python /afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/config/doPlots.py plots.py


python /afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/config/FCCAnalysisRun.py /afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/240/analysis_stage1.py


cd /afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240

cd /afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/combination

cd /afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/Fits/240/qqH
root combinedModel240.C



rsync -avz --include='*_histo.root' --exclude='*' /eos/user/n/niharrin/llr/presel/240/llH/source/ /afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/240/presel/histos/


rsync -avz --include='*_histo.root' --exclude='*' /eos/user/n/niharrin/llr/presel/365/source/ /afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/365/presel/histos/

rsync -avz --include='*_ecm365.root' --exclude='*' /eos/user/n/niharrin/llr/presel/365/source/ /afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/365/presel/

/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/240/categories/ZmumuH

/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/365/categories/

rsync -avz /eos/user/n/niharrin/llr/presel/365/source/p8_ee_ZH_ecm365.root /afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/365/presel/


rsync -avz --include='*_ecm365.root' --exclude='*' /afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/365/presel/ /eos/user/n/niharrin/llr/presel/365/source/




