# meshoptimizer
Mesh optimizer is an efficient mesh optimization library that reduces the storage size of 3D mesh data and improves rendering performance through various techniques. It is mainly used for optimizing 3D models (such as pixel silver optimization, vertex caching optimization, over drawing optimization, vertex acquisition optimization, vertex quantization, shadow indexing), especially when dealing with a large number of polygon 3D models, which can significantly reduce rendering burden and improve running efficiency.

## Use Cases of meshoptimizer
Gltf (Graphics Library Transmission Format) is a royalty free specification aimed at improving the efficiency of application transmission and loading of 3D scenes and models.
The introduction of meshoptimizer on OpenHarmony is mainly for decompressing the Ext_meshopt_compress extension format in gltf. 

## Directory Structure 
```
demo        # demo file
extern      # third-party source code
gltf        # gltfpack is a tool that can automatically optimize gltf files, reducing download size and improving loading and rendering speed
js          # this folder contains JavaScript/WebAssembly modules that can be used to access some functions of the meshoptimizer library
src         # C++ source code directory of meshoptimizer containing decompression functions
CMakeLists.txt      # build description file
LICENSE.md      # license statement
README.MD       # software description 
```


## The adaptation of meshoptimizer for OpenHarmony
OpenHarmony only compiles the source code and header files under the src/ directory in the meshoptimizer repository. meshoptimizer is introduced into the thirdparty directory of OpenHarmony and compiled using the method of dependent components in OpenHarmony. 

## Main Code Download 
```
repo init -u https://gitee.com/openharmony/manifest.git -b master --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


## Depend on the modules in use. 
```
deps = ["//third_party/meshoptimizer:meshoptimizer"]
```


## Preprocessing 
```
./build/prebuilts_download.sh
```


## Compilation 
```
./build.sh --product-name rk3568 --ccache
```


## Relevant References 
https://github.com/zeux/meshoptimizer


## License
This project is subject to the license described in LICENCE. 

## Related warehouse 
meshoptimizer

##Usage in OpenHarmony
###Object oriented
Developers of system applications and 3D graphics engines.
###Guidance and reference
```
deps = ["//third_party/meshoptimizer:meshoptimizer"]
```
Introduce this third-party library.
```
include "meshoptimizer.h"
meshopt_decodeVertexBuffer();
meshopt_decodeFilterOct();
meshopt_decodeFilterQuat();
meshopt_decodeFilterExp();
meshopt_decodeIndexBuffer();
```
Introduce the meshoptimizer. h header file and use the corresponding functions. For specific instructions on the functions, please refer to: https://github.com/zeux/meshoptimizer