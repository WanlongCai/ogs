if [ -n "$ZSH_VERSION" ]; then
    DIR=$( cd $(dirname "${(%):-%x}") ; pwd -P )
else
    DIR=$( cd $(dirname "${BASH_SOURCE[0]}") ; pwd -P )
fi

source $DIR/cli.sh
module load vtk/8.2.0/foss2019b/openmpi
export CC=mpicc
export CXX=mpic++
