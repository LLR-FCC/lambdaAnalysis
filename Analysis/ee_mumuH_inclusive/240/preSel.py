#python examples/FCCee/higgs/mH-recoil/mumu/preSel.py

from config.common_defaults import deffccdicts
import os

basedir=os.path.join(os.getenv('FCCDICTSDIR', deffccdicts), '') + "yaml/FCCee/spring2021/IDEA/"
#outdir="outputs/FCCee/higgs/mH-recoil/mumu/"
#basedir="/eos/experiment/fcc/ee/generation/DelphesEvents/spring2021/IDEA/"
outdir="/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/ee_mumuH_inclusive/240/presel/"

import multiprocessing
NUM_CPUS = int(multiprocessing.cpu_count()-2)

process_list=['wzp6_ee_mumuH_ecm240','p8_ee_WW_ecm240','p8_ee_ZZ_ecm240','p8_ee_Zll_ecm240', 'wzp6_gaga_mumu_60_ecm240']
fraction=1


import config.runDataFrame as rdf
myana=rdf.runDataFrame(basedir,process_list)
myana.run(ncpu=NUM_CPUS,fraction=fraction,outDir=outdir)