setup_actual=$(readlink -f /cvmfs/sw.hsf.org/spackages5/key4hep-stack/2022-04-25/x86_64-centos7-gcc11.2.0-opt/*/setup.sh)
setup_actual=$(echo $setup_actual | cut --delimiter " " --fields 1)
export key4hep_stack_version=$(echo "$setup_actual"| grep -Eo 'key4hep-stack[^/]*/[^/]*')
echo "Setting up the latest Key4HEP software stack from CVMFS ..."
echo " ...  Key4HEP release: ${key4hep_stack_version}"
echo " ... Use the following command to reproduce the current environment: "
echo " ... "
echo "         source ${setup_actual}"
echo " ... "
export PATH=/cvmfs/sft.cern.ch/lcg/releases/ccache/3.7.1-7651f/x86_64-centos7-gcc8-opt/bin:$PATH
export PATH=/cvmfs/sft.cern.ch/lcg/contrib/git/2.28.0/x86_64-centos7/bin:$PATH
#source /cvmfs/sw.hsf.org/contrib/spack/share/spack/setup-env.sh
source ${setup_actual}
echo " ... done. "
