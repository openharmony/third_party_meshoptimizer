# meshoptimizer
meshoptimizer 是一个高效的网格优化库，通过多种技术减少3D网格数据的存储大小和提升渲染性能。它主要用于图形学和游戏开发领域，尤其是处理大量多边形的3D模型时，能够显著降低渲染负担，提高运行效率。

## meshoptimizer使用场景
OpenHarmony上引入meshoptimizer，主要用于对gltf中Ext_meshopt_compress扩展格式的解压缩。

## 目录结构
```
demo        # demo文件
extern      # 三方源代码
gltf        # gltfpack 是一款能够自动优化gltf文件的工具，减少下载大小并提升加载和渲染速度
js          # 此文件夹包含可用于访问meshoptimizer库部分功能的Javascript/WebAssembly模块
src         # meshoptimizer C++源代码目录包含解压缩功能
CMakeLists.txt      # 编译描述文件
LICENSE.md      # 版权说明
README.MD       # 软件说明      
```

## OpenHarmony对于meshoptimizer的适配
OpenHarmony只编译使用meshoptimizer仓库中src/目录下的源代码和头文件。meshoptimizer引入openharmony的thirdparty目录下，使用OpenHarmony中依赖部件的方式进行编译。

## 主干代码下载
```
repo init -u https://gitee.com/openharmony/manifest.git -b master --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

## 在使用的模块进行依赖
```
deps = ["//third_party/meshoptimizer:meshoptimizer"]
```

## 预处理
```
./build/prebuilts_download.sh
```

## 编译
```
./build.sh --product-name rk3568 --ccache
```

## 相关参考
https://github.com/zeux/meshoptimizer

## 许可证
本项目遵从LICENCE中所描述的许可证

## 相关仓
meshoptimizer