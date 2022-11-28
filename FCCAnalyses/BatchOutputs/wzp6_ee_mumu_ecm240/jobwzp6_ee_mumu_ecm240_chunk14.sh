#!/bin/bash
cd /afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses
source setup2.sh
source setup.sh
cd /afs/cern.ch/user/n/niharrin/work/public/MA/FCCeePhysicsPerformance/case-studies/higgs/dataframe
source localSetup.sh
cd /afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/BatchOutputs
mkdir jobwzp6_ee_mumu_ecm240_chunk14
cd jobwzp6_ee_mumu_ecm240_chunk14
python /afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/config/FCCAnalysisRun.py /afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/240/analysis_stage1.py --batch --output /eos/user/n/niharrin/llr/presel/240/llH/source/wzp6_ee_mumu_ecm240/chunk14.root --files-list  /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_017679686.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_077353930.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_190040934.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_065003042.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_100243199.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_079420399.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_012313238.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_017709438.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_002872423.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_097279268.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_108455070.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_028786760.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_076359745.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_066040032.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_092450944.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_032928620.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_166860885.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_161980966.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_189835460.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_053418175.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_175412412.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_154122988.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_006313459.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_111303300.root