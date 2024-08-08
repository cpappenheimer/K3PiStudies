# K3Pi

## Conda environment
```
conda env create --name <environment name> --file=conda_environment.yml
conda activate <environment name>
```

## Building the code
```
mkdir build
cmake -S <path to K3PiStudies root> -B <path to build dir> 
```
(add `-DCMAKE_BUILD_TYPE=Debug` flag for debug build)
```
cmake --build <path to build dir>  
```
(`-v` for verbose builds, `-j N` for parallel builds on `N` cores)

## Running the code
To view list of command line options run
```
/build/angular_dists/src/K3PiStudies --help
```

Edit `RunK3PiStudies.py` to choose user inputs then
```
python RunK3PiStudies.py
```
