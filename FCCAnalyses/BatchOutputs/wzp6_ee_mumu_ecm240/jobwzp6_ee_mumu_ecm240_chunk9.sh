#!/bin/bash
cd /afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses
source setup2.sh
source setup.sh
cd /afs/cern.ch/user/n/niharrin/work/public/MA/FCCeePhysicsPerformance/case-studies/higgs/dataframe
source localSetup.sh
cd /afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/BatchOutputs
mkdir jobwzp6_ee_mumu_ecm240_chunk9
cd jobwzp6_ee_mumu_ecm240_chunk9
python /afs/cern.ch/user/n/niharrin/work/public/MA/FCCAnalyses/config/FCCAnalysisRun.py /afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/240/analysis_stage1.py --batch --output /eos/user/n/niharrin/llr/presel/240/llH/source/wzp6_ee_mumu_ecm240/chunk9.root --files-list  /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_118377003.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_116559867.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_169460007.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_061055431.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_070679897.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_067789987.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_136117347.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_199855497.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_015966558.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_128830419.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_181905207.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_183368325.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_068007513.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_040915952.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_106751642.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_184705551.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_023589089.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_013493434.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_142467132.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_080445260.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_092239970.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_040969776.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_050219236.root /eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/wzp6_ee_mumu_ecm240/events_082678658.root
