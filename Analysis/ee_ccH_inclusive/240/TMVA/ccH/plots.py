import ROOT

# global parameters
intLumi        = 5.0e+06 #in pb-1
#customLabel    = 'e^{+}e^{-} #rightarrow ZH #rightarrow bb + X'
#customLabel    = 'e^{+}e^{-} #rightarrow ZH #rightarrow jb + X'
#customLabel    = 'e^{+}e^{-} #rightarrow ZH #rightarrow ij + X'
customLabel    = 'e^{+}e^{-} #rightarrow ZH #rightarrow cc + X'
#customLabel    = 'e^{+}e^{-} #rightarrow ZH #rightarrow jc + X'
delphesVersion = '3.4.2'
energy         = 240.0
collider       = 'FCC-ee'
inputDir       = '/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/ee_bbH_inclusive/240/presel_10/'
formats        = ['png']
yaxis          = ['lin','log']
stacksig       = ['stack','nostack']
outdir         = '/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/ee_ccH_inclusive/240/TMVA/ccH/plots/'
scaleSig       = 1.0
#ana_tex    = 'M_{Rec} \in [100, 160] GeV, M_{ij} \in [86, 96] GeV'
ana_tex        = ''

#variables = ['mz','mz_zoom', 'm_rec', 'z_pt', 'ht']
#variables = ['m_rec', 'ht', 'htheta', 'hrtheta', 'pT1', 'pT2', 'E1', 'E2', 'Eta1', 'Eta2', 'Acoll_ij', 'Jet_No', 'bJet_No', 'pT_ij', 'mz', 'FinalClassifier_BDT', 'FinalClassifier_DNN', 'FinalClassifier_MLP']
variables = ['m_rec', 'jet_ht', 'htheta', 'hrtheta', 'pT1', 'pT2', 'E1', 'E2', 'Eta1', 'Eta2', 'Acoll_ij', 'Jet_No', 'bJet_No', 'pT_ij', 'M_ij', 'zed_bJet_No', 'zed_cJet_No', 'zed_lJet_No', 'MET', 'MET_Angle', 'AcollPaPb_ij', 'DeltaEta', 'DeltaPhi', 'cJet_No', 'FinalClassifier_BDT_cc']

###Dictonnary with the analysis name as a key, and the list of selections to be plotted for this analysis. The name of the selections should be the same than in the final selection
selections = {}
#selections['ZH']   = ["sel0", "sel1", "sel2", "sel6", "sel7", "sel8", "sel9", "sel10", "sel11", "sel13"]
#selections['ZH']   = ["sel0", "sel1", "sel2", "sel6", "sel7", "selZbbFinal", "selZbbFinal2", "selZbbFinal3_0", "selZbbFinal3", "selZjbFinal", "selZjbFinal2", "selZjbFinal3", "selZjjFinal", "selZjjFinal2", "selZjjFinal3", "selZccFinal", "selZccFinal2", "selZccFinal3"]
#selections['ZH']   = ["selZbbFinal", "selZbbFinal2", "selZbbFinal3_0", "selZbbFinal3"]
#selections['ZH']   = ["selZjbFinal", "selZjbFinal2", "selZjbFinal3", "selZjbFinal4", "selZjbFinal5", "selZjbFinal6", "selZjbFinal7", "selZjbFinal8", "selZjbFinal9", "selZjbFinal10", "selZjbFinal11", "selZjbFinal12", "selZjbFinal13", "selZjbFinal14", "selZjbFinal15"]
#selections['ZH']   = ["selZjjFinal", "selZjjFinal2", "selZjjFinal3", "selZjjFinal4", "selZjjFinal5", "selZjjFinal6", "selZjjFinal7", "selZjjFinal8"]
#selections['ZH']   = ["sel0", "selZccFinal_noBDT"]
selections['ZH']   = ["sel0", "selZccFinal_noBDT", "selZccFinal"]
#selections['ZH']   = ["selZjcFinal", "selZjcFinal2", "selZjcFinal3"]
#selections['ZH_2'] = ["sel0", "sel1", "sel2", "sel3", "sel4", "sel5", "sel6"]

#label={}
#label['selZbbFinal3'] = "M_{Rec} \in [100, 160] GeV"

extralabel = {}
extralabel['sel0'] = "No cut"
extralabel['selZccFinal_noBDT'] = "N_{bZ} = 0, N_{cZ} = 2, M_{Rec} #in #[]{100, 160} GeV, M_{ij} #in #[]{86, 96} GeV"
extralabel['selZccFinal'] = "selZccFinal_noBDT cuts, #beta_{cc} > 0.1417"
#extralabel['selZccFinal2'] = "MET < 35 GeV, #beta_{cc} > -0.09"
#extralabel['selZccFinal3'] = "MET < 35 GeV, #||{cos(#theta_{Miss})} < 0.98, #beta_{cc} > -0.09"
#extralabel['selZccFinal4'] = "MET < 35 GeV, #||{cos(#theta_{Miss})} < 0.98, #beta_{cc} > -0.09"
#extralabel['selZccFinal5'] = "MET < 35 GeV, #||{cos(#theta_{Miss})} < 0.98, #beta_{cc} > -0.09"
#extralabel['selZccFinal6'] = "MET < 35 GeV, #||{cos(#theta_{Miss})} < 0.98, #beta_{cc} > -0.09"
#extralabel['selZccFinal7'] = "MET < 35 GeV, #||{cos(#theta_{Miss})} < 0.98, #beta_{cc} > -0.09"
#extralabel['selZccFinal_op'] = "MET < 35 GeV, #||{cos(#theta_{Miss})} < 0.98, #beta_{cc} > -0.09"
#extralabel['selZccFinal7'] = "MET < 35 GeV, #||{cos(#theta_{Miss})} < 0.98, #beta_{cc} > -0.09"
#extralabel['selZccFinal8'] = "MET < 35 GeV, #||{cos(#theta_{Miss})} < 0.98, #beta_{cc} > -0.09"
#extralabel['selZccFinal8'] = "MET < 35 GeV, #||{cos(#theta_{Miss})} < 0.98, #beta_{jb} > -0.09"
#extralabel['selZccFinal9'] = "MET < 35 GeV, #||{cos(#theta_{Miss})} < 0.98, #beta_{jb} > -0.09"
#extralabel['selZccFinal10'] = "MET < 35 GeV, #||{cos(#theta_{Miss})} < 0.98, #beta_{jb} > -0.09"
#extralabel['selZccFinal11'] = "MET < 35 GeV, #||{cos(#theta_{Miss})} < 0.98, #beta_{jb} > -0.09"
#extralabel['selZccFinal12'] = "MET < 35 GeV, #||{cos(#theta_{Miss})} < 0.98, #beta_{jb} > -0.09"
#extralabel['selZccFinal13'] = "MET < 35 GeV, #||{cos(#theta_{Miss})} < 0.98, #beta_{jb} > -0.09"
#extralabel['selZccFinal14'] = "MET < 35 GeV, #||{cos(#theta_{Miss})} < 0.98, #beta_{jb} > -0.09"
#extralabel['selZccFinal15'] = "MET < 35 GeV, #||{cos(#theta_{Miss})} < 0.98, #beta_{jb} > -0.09"






colors = {}
colors['ZH'] = ROOT.kRed
colors['WW'] = ROOT.kBlue+1
colors['ZZ'] = ROOT.kGreen+2
colors['VV'] = ROOT.kGreen+3
colors['Zqq'] = ROOT.kOrange+2

plots = {}
plots['ZH'] = {'signal':{'ZH':['wzp6_ee_qqH_ecm240']},
               'backgrounds':{'WW':['p8_ee_WW_ecm240'],
                              'ZZ':['p8_ee_ZZ_ecm240'],
                              'Zqq':['p8_ee_Zqq_ecm240']}
           }


plots['ZH_2'] = {'signal':{'ZH':['wzp6_ee_qqH_ecm240']},
                 'backgrounds':{'VV':['p8_ee_WW_ecm240','p8_ee_ZZ_ecm240'],
                                'Zqq':['p8_ee_Zqq_ecm240']}
             }

legend = {}
legend['ZH'] = 'ZH'
legend['WW'] = 'WW'
legend['ZZ'] = 'ZZ'
legend['VV'] = 'VV boson'
legend['Zqq'] = 'Zqq'



