import ROOT

# global parameters
intLumi        = 5.0e+06 #in pb-1
customLabel    = 'e^{+}e^{-} #rightarrow ZH #rightarrow e^{+}e^{-} + X'
delphesVersion = '3.4.2'
energy         = 240.0
collider       = 'FCC-ee'
inputDir       = '/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/240/presel/'
formats        = ['png']
yaxis          = ['lin','log']
stacksig       = ['stack','nostack']
outdir         = '/afs/cern.ch/user/n/niharrin/work/public/MA/Analysis/source/240/categories/ZeeH/plots/'
ana_tex        = ''

variables = ['mz','mz_zoom','leptonic_recoil_m','leptonic_recoil_m_zoom','leptonic_recoil_m_zoom2', 'leptonic_pt', 'MET_costheta']

selections = {}
selections['ZH']   = ["sel_ZeeH","sel_ZeeH1", "sel_ZeeH2", "sel_ZeeH3", "sel_ZeeH4", "sel_ZeeH5"]
selections['ZH_2'] = ["sel_ZeeH","sel_ZeeH1", "sel_ZeeH2", "sel_ZeeH3", "sel_ZeeH4", "sel_ZeeH5"]

extralabel = {}
extralabel['sel_ZeeH'] = "N_{Z} = 1"
extralabel['sel_ZeeH1'] = "N_{Z} = 1, M_{Tij} #in #[]{86, 96} GeV"
extralabel['sel_ZeeH2'] = "N_{Z} = 1, M_{Tij} #in #[]{86, 96} GeV, M_{Rec} #in #[]{120, 140} GeV"
#Immer N_{Z} = 1, #splitline{M_{Tij} #in #[]{86, 96} GeV}{M_{Rec} #in #[]{120, 140} GeV}
extralabel['sel_ZeeH3'] = "p_{Tij} #in #[]{20, 70} GeV"
extralabel['sel_ZeeH4'] = "Final selections"
extralabel['sel_ZeeH5'] = "M_{Rec} #in #[]{122, 135} GeV, p_{Tij} #in #[]{20, 70} GeV, #||{cos(#theta_{Miss})} < 0.98"


colors = {}
colors['ZH'] = ROOT.kRed
colors['WW'] = ROOT.kBlue+1
colors['ZZ'] = ROOT.kGreen+2
colors['VV'] = ROOT.kGreen+3
colors['Zll'] = ROOT.kOrange

plots = {}
plots['ZH'] = {'signal':{'ZH':['wzp6_ee_eeH_ecm240']},
               'backgrounds':{'WW':['p8_ee_WW_ecm240'],
                              'ZZ':['p8_ee_ZZ_ecm240'],
                              'Zll':['p8_ee_Zll_ecm240']}
           }


plots['ZH_2'] = {'signal':{'ZH':['wzp6_ee_eeH_ecm240']},
                 'backgrounds':{'VV':['p8_ee_WW_ecm240','p8_ee_ZZ_ecm240'],
                                'Zll':['p8_ee_Zll_ecm240']}
             }

legend = {}
legend['ZH'] = 'ZH'
legend['WW'] = 'WW'
legend['ZZ'] = 'ZZ'
legend['VV'] = 'VV boson'
legend['Zll'] = 'Z #rightarrow ll'



