<!-- ![fig](https://raw.githubusercontent.com/ChenZhu-Xie/geometric_optics_2_discrete_mathematics/master/img/1.cover.png "『第三本书』的『狭义相对论』相关『章节』") -->
![fig](https://gitee.com/ChenZhu-Xie/geometric_optics_2_discrete_mathematics/raw/master/img/1.cover.png "『多重·辗转相除法』自动运行在『杜瓦瓶』=『纯反射∧无吸收の含缺口の黑体』中")

# 一场探索 ☛『几何光学』中的『离散数学』

## 关于
* 该探索过程 👉 [几何光学 in 离散数学](https://gitee.com/ChenZhu-Xie/geometric_optics_2_discrete_mathematics)
    1. 由 .ppt 描述 ⊊ 👉[「1.『多重·辗转相除法』自动运行在『杜瓦瓶』=『纯反射∧无吸收の含缺口の黑体』中.pptx」](https://gitee.com/ChenZhu-Xie/geometric_optics_2_discrete_mathematics/raw/master/1.『多重·辗转相除法』自动运行在『杜瓦瓶』=『纯反射∧无吸收の含缺口の黑体』中.pptx)
    2. 使用模拟器 ⊷ 👉 [2D 射線追蹤 模拟](https://gitee.com/ChenZhu-Xie/ray_optics__xcz)
        * 被 .pptx 使用 ⊶ 👉[「A_guided_tour_to_Ray_&_Wave_Optics_Simulation」](https://gitee.com/ChenZhu-Xie/ray_optics__xcz/raw/master/A_guided_tour_to_Ray_&_Wave_Optics_Simulation.pptx)
            * 链接到模型 ✉ 👉 [NLAST-vector 模型 (私有)](https://gitee.com/ChenZhu-Xie/NLAST_private)
                * 包含文章 ⊋ 👉 [Berry-Mcleod 文章 (私有)](https://gitee.com/ChenZhu-Xie/Berry_Mcleod_paper__private)
                * 『波动光学』in『偏微分方程 (PDEs)』
    <!-- 3. 在书中涉及 ⊊ [Ray & Wave Optics simulation](https://gitee.com/ChenZhu-Xie/geometric_optics_2_discrete_mathematics/master/A_guided_tour_to_Ray_&_Wave_Optics_Simulation.pptx) -->
    3. 在书中涉及 ⊊ 👉 [Illusions_of_Illustrations_·_Zodiac](https://gitee.com/ChenZhu-Xie/3_books_with_cpp/tree/master/cpp_codes_for_book2『Illusions_of_Illustrations_·_Zodiac』)
        * 被书们包含 ⊂ 👉 [三本 电子书](https://gitee.com/ChenZhu-Xie/3_books_with_cpp)
    4. 可能有关于 ✉ 👉[「不可单点照亮」的「彭罗斯房间」](https://www.bilibili.com/video/BV18p421d7NK)
* English「README」ⓔ 👉 [Berry-Mcleod paper (Private)](https://github.com/ChenZhu-Xie/geometric_optics_2_discrete_mathematics)

## 介绍
* 『该探索过程』属于『第二本书 的 案例』之一
    * 利用『辗转相除法』理解：不封口的『杜瓦瓶』内的『银镜内壁』，对光的『多重反射』
* 讨论了 代数（数学）在 几何（光学）中的 用武之地
    * 光源在外部：从外部射入『纯反射黑体』，光最终会从缺口处出来，为什么？
    * 光源在内部：光源在『纯反射黑体』内部，光不一定会从缺口出来，条件是？

## 实施
1. 思想上：将『球面凹反镜黑体』内的『光学过程』转换/抽象为『数学过程』
    * 见[「1.『多重·辗转相除法』自动运行在『杜瓦瓶』=『纯反射∧无吸收の含缺口の黑体』中.pptx」](https://gitee.com/ChenZhu-Xie/geometric_optics_2_discrete_mathematics/raw/master/1.『多重·辗转相除法』自动运行在『杜瓦瓶』=『纯反射∧无吸收の含缺口の黑体』中.pptx)中的动画
    * 见 [2.『Illusions_of_Illustrations_·_Zodiac』.pdf](https://gitee.com/ChenZhu-Xie/3_books_with_cpp/tree/master/2.『Illusions_of_Illustrations_·_Zodiac』(C++).pdf) 第 8 页『圆向量的起源』
2. 光学拓展：『含缺口的积分球』➞『有出口的迷宫』
    * 相同的结论，适用于『其他任何形状』，如『迷宫形』谐振腔
    * 也就是说，『黑体形状』不一定是『球形』，其内部可以『任意复杂』
        * 若光源『在迷宫内部』，则光线 "可能解/出不了该迷宫"
        * 见案例『[用一条光线解迷宫](https://phydemo.app/ray-optics/cn/gallery/maze-solution)』
        * 若光源『在迷宫外部』，则光线 "一定能再次从迷宫口出来"
        * ![fig](https://gitee.com/ChenZhu-Xie/geometric_optics_2_discrete_mathematics/raw/master/img/maze_1.1.png "What goes up, must come down.")
        * ![fig](https://gitee.com/ChenZhu-Xie/geometric_optics_2_discrete_mathematics/raw/master/img/maze_2.1.png "What goes in, must come out.")
3. 数学拓展：『二元』➞『多元』一次不定方程 の『特解 & 通解』
    * 打开 文件夹 "[cpp_codes_for_book2『Illusions_of_Illustrations_·_Zodiac』](https://gitee.com/ChenZhu-Xie/3_books_with_cpp/tree/master/cpp_codes_for_book2『Illusions_of_Illustrations_·_Zodiac』)"。
    * 使用 Visual C++ 6.0 运行里面的[「12.第10个程序的改良版(2+5+8b).cpp」](https://gitee.com/ChenZhu-Xie/3_books_with_cpp/tree/master/cpp_codes_for_book2『Illusions_of_Illustrations_·_Zodiac』/12.第10个程序的改良版(2+5+8b).cpp)
        * 即使用 `Microsoft Visual Studio C++ 6.0\Common\MSDev98\Bin\MSDEV.EXE`。
        * [VC6.0 下载 & 安装](https://mp.weixin.qq.com/s/6YNbpj6RlCNh9zZd5K1wQA)；也推荐使用更高版本的 C++，但可能无法运行此旧程序？
    * ![fig](https://gitee.com/ChenZhu-Xie/geometric_optics_2_discrete_mathematics/raw/master/img/book_2-6.png "『多重·辗转相除法』解『多元·一次不定方程』")
    * 见 [2.『Illusions_of_Illustrations_·_Zodiac』.pdf](https://gitee.com/ChenZhu-Xie/3_books_with_cpp/tree/master/2.『Illusions_of_Illustrations_·_Zodiac』(C++).pdf) 第 10 页『多元一次不定方程及“超级辗转相除法”』

## 历史
* 这次探索 👉 [几何光学 in 离散数学](https://gitee.com/ChenZhu-Xie/geometric_optics_2_discrete_mathematics)
    * （个人时间）25 岁 10 月
    * （个人阶段）博士 2 年级·寒假 (1.5 / 3.0)
    * （世界时间）2024.02

<!-- ## 软件架构
软件架构说明


## 安装教程

1.  xxxx
2.  xxxx
3.  xxxx

## 使用说明

1.  xxxx
2.  xxxx
3.  xxxx

## 参与贡献

1.  Fork 本仓库
2.  新建 Feat_xxx 分支
3.  提交代码
4.  新建 Pull Request


## 特技

1.  使用 Readme\_XXX.md 来支持不同的语言，例如 Readme\_en.md, Readme\_zh.md
2.  Gitee 官方博客 [blog.gitee.com](https://blog.gitee.com)
3.  你可以 [https://gitee.com/explore](https://gitee.com/explore) 这个地址来了解 Gitee 上的优秀开源项目
4.  [GVP](https://gitee.com/gvp) 全称是 Gitee 最有价值开源项目，是综合评定出的优秀开源项目
5.  Gitee 官方提供的使用手册 [https://gitee.com/help](https://gitee.com/help)
6.  Gitee 封面人物是一档用来展示 Gitee 会员风采的栏目 [https://gitee.com/gitee-stars/](https://gitee.com/gitee-stars/) -->
