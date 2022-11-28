import ROOT

# global parameters
intLumi        = 5.0e+06 #in pb-1
#customLabel    = 'e^{+}e^{-} #rightarrow ZH #rightarrow bb + X'
#customLabel    = 'e^{+}e^{-} #rightarrow ZH #rightarrow jb + X'
#customLabel    = 'e^{+}e^{-} #rightarrow ZH #rightarrow ij + X'
#customLabel    = 'e^{+}e^{-} #rightarrow ZH #rightarrow cc + X'
customLabel    = 'e^{+}e^{-} #rightarrow ZH #rightarrow jc + X'
delphesVersion = '3.4.2'
energy         = 240.0
collider       = 'FCC-ee'
inputDir       = '/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/ee_bbH_inclusive/240/presel_10/'
formats        = ['png']
yaxis          = ['lin','log']
stacksig       = ['stack','nostack']
outdir         = '/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/ee_bbH_inclusive/240/plots/'
scaleSig       = 1.0
#ana_tex    = 'M_{Rec} \in [100, 160] GeV, M_{ij} \in [86, 96] GeV'
ana_tex        = ''

#variables = ['mz','mz_zoom', 'm_rec', 'z_pt', 'ht']
#variables = ['m_rec', 'ht', 'htheta', 'hrtheta', 'pT1', 'pT2', 'E1', 'E2', 'Eta1', 'Eta2', 'Acoll_ij', 'Jet_No', 'bJet_No', 'pT_ij', 'mz', 'FinalClassifier_BDT', 'FinalClassifier_DNN', 'FinalClassifier_MLP']
variables = ['m_rec', 'jet_ht', 'htheta', 'hrtheta', 'pT1', 'pT2', 'E1', 'E2', 'Eta1', 'Eta2', 'Acoll_ij', 'Jet_No', 'bJet_No', 'pT_ij', 'M_ij', 'zed_bJet_No', 'zed_cJet_No', 'zed_lJet_No', 'MET', 'MET_Angle', 'FinalClassifier_BDT_bb', 'FinalClassifier_BDT_jb', 'FinalClassifier_BDT_jj', 'FinalClassifier_BDT_cc']

###Dictonnary with the analysis name as a key, and the list of selections to be plotted for this analysis. The name of the selections should be the same than in the final selection
selections = {}
#selections['ZH']   = ["sel0", "sel1", "sel2", "sel6", "sel7", "sel8", "sel9", "sel10", "sel11", "sel13"]
#selections['ZH']   = ["sel0", "sel1", "sel2", "sel6", "sel7", "selZbbFinal", "selZbbFinal2", "selZbbFinal3_0", "selZbbFinal3", "selZjbFinal", "selZjbFinal2", "selZjbFinal3", "selZjjFinal", "selZjjFinal2", "selZjjFinal3", "selZccFinal", "selZccFinal2", "selZccFinal3"]
#selections['ZH']   = ["selZbbFinal", "selZbbFinal2", "selZbbFinal3_0", "selZbbFinal3"]
#selections['ZH']   = ["selZjbFinal", "selZjbFinal2", "selZjbFinal3"]
#selections['ZH']   = ["selZjjFinal", "selZjjFinal2", "selZjjFinal3"]
#selections['ZH']   = ["selZccFinal", "selZccFinal2", "selZccFinal3", "selZccFinal0"]
selections['ZH']   = ["selZjcFinal", "selZjcFinal2", "selZjcFinal3"]
#selections['ZH_2'] = ["sel0", "sel1", "sel2", "sel3", "sel4", "sel5", "sel6"]

#label={}
#label['selZbbFinal3'] = "M_{Rec} \in [100, 160] GeV"

extralabel = {}
extralabel['sel0'] = "Selection: N_{Jets} >= 0"
extralabel['sel1'] = "Selection: N_{Jets} > 2"
extralabel['sel2'] = "Selection: N_{Jets} > 2, N_{bJets} > 1"
extralabel['sel7'] = "Selection: N_{Jets} > 2, N_{bJets} > 1, Theta_ij < 2.9, Theta_ij > 0.25"
#extralabel['sel8'] = "Selection: N_{Jets} > 2, N_{bJets} > 1, Theta_ij < 2.9, Theta_ij > 0.25, Acoll(i,j) < 1.1"
#extralabel['sel9'] = "Selection: N_{Jets} > 2, N_{bJets} > 1, Theta_ij < 2.9, Theta_ij > 0.25, Acoll(i,j) < 1.1"
#extralabel['sel10'] = "Selection: N_{Jets} > 2, N_{bJets} > 1, Theta_ij < 2.9, Theta_ij > 0.25, Acoll(i,j) < 1.1"
#extralabel['sel11'] = "Selection: N_{Jets} > 2, N_{bJets} > 1, Theta_ij < 2.9, Theta_ij > 0.25, Acoll(i,j) < 1.1"
extralabel['sel6'] = "Selection: N_{Jets} > 2, N_{bJets} > 1, Theta_ij < 2.9, Theta_ij > 0.25, Acoll(i,j) < 1.1"
#extralabel['sel13'] = "Selection: N_{Jets} > 2, N_{bJets} > 1, Theta_ij < 2.9, Theta_ij > 0.25, Acoll(i,j) < 1.1"
#For them always: M_{Rec} \in [100, 160] GeV, M_{ij} \in [86, 96] GeV
extralabel['selZbbFinal'] = "#beta_{bb} > -0.08"
extralabel['selZbbFinal2'] = "MET < 35 GeV, #beta_{bb} > -0.08"
extralabel['selZbbFinal3_0'] = 'MET < 35 GeV, #||{cos(#theta_{Miss})} < 0.98'
extralabel['selZbbFinal3'] = 'MET < 35 GeV, #||{cos(#theta_{Miss})} < 0.98, #beta_{bb} > -0.08'
extralabel['selZjbFinal'] = "#beta_{jb} > -0.09"
extralabel['selZjbFinal2'] = "MET < 35 GeV, #beta_{jb} > -0.09"
extralabel['selZjbFinal3'] = "MET < 35 GeV, #||{cos(#theta_{Miss})} < 0.98, #beta_{jb} > -0.09"
extralabel['selZjjFinal'] = "#beta_{jj} > -0.06"
extralabel['selZjjFinal2'] = "MET < 35 GeV, #beta_{jj} > -0.06"
extralabel['selZjjFinal3'] = "MET < 35 GeV, #||{cos(#theta_{Miss})} < 0.98, #beta_{jj} > -0.06"
extralabel['selZccFinal'] = "#beta_{cc} > 0.06"
extralabel['selZccFinal2'] = "MET < 35 GeV, #beta_{cc} > 0.06"
extralabel['selZccFinal3'] = "MET < 35 GeV, #||{cos(#theta_{Miss})} < 0.98, #beta_{cc} > 0.06"
extralabel['selZccFinal0'] = "MET < 35 GeV, #||{cos(#theta_{Miss})} < 0.98"
extralabel['selZjcFinal'] = "#beta_{jc} > 0.05"
extralabel['selZjcFinal2'] = "MET < 35 GeV, #beta_{jc} > 0.05"
extralabel['selZjcFinal3'] = "MET < 35 GeV, #||{cos(#theta_{Miss})} < 0.98, #beta_{jc} > 0.05"
#extralabel['sel8'] = "Selection: N_{Jets} > 2, N_{bJets} > 1, Theta_ij < 2.9, Theta_ij > 0.25, Acoll(i,j) < 1.1"
#extralabel['sel1'] = "Selection: N_{Z} = 1, n_{\mathrm{b jets} > 1, H_{T} > 10 GeV"
#extralabel['sel2'] = "Selection: N_{Z} = 1, n_{\mathrm{b jets} > 1, H_{T} > 10 GeV, M_{jj} > 45 GeV"
#extralabel['sel3'] = "Selection: N_{Z} = 1, n_{\mathrm{b jets} > 1, H_{T} > 10 GeV, M_{jj} > 45 GeV, p_{T, jj} > 60 GeV"
#extralabel['sel4'] = "Selection: N_{Z} = 1, n_{\mathrm{b jets} > 1, H_{T} > 10 GeV, M_{jj} > 45 GeV, p_{T, jj} > 60 GeV"
#extralabel['sel5'] = "Selection: N_{Z} = 1, n_{\mathrm{b jets} > 1, H_{T} > 10 GeV, M_{jj} > 45 GeV, p_{T, jj} > 60 GeV"
#extralabel['sel6'] = "Selection: N_{Z} = 1, n_{\mathrm{b jets} > 1, H_{T} > 10 GeV, M_{jj} > 45 GeV, p_{T, jj} > 60 GeV"
#extralabel['sel4'] = "Selection: N_{Z} = 1; 86 GeV < m_{Z} < 96 GeV; 120 GeV < M_{Recoil} < 140 GeV; 20 GeV < p_{T} < 70 GeV; abs(cos_{\theta}) < 0.98"
#extralabel['sel5'] = "Selection: N_{Z} = 1; 86 GeV < m_{Z} < 96 GeV; 122 GeV < M_{Recoil} < 135 GeV; 20 GeV < p_{T} < 70 GeV; abs(cos_{\theta}) < 0.98"

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



