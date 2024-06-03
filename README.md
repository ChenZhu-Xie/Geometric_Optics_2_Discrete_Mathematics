[![fig](https://raw.githubusercontent.com/ChenZhu-Xie/geometric_optics_2_discrete_mathematics/master/img/1.cover.png "Multiple Euclidean algorithm runs automatically in『Dewar bottle』=『pure-reflection non-absorbing notched blackbody』")](https://github.com/ChenZhu-Xie/geometric_optics_2_discrete_mathematics/raw/master/1.『多重·辗转相除法』自动运行在『杜瓦瓶』=『纯反射∧无吸收の含缺口の黑体』中.pptx "Multiple Euclidean algorithm runs automatically in『Dewar bottle』=『pure-reflection non-absorbing notched blackbody』")

# An expedition ☛『Discrete Mathematics』in『Geometric Optics』

## About
* This dive 👉 [『Geometric optics』in『Discrete mathematics』](https://github.com/ChenZhu-Xie/geometric_optics_2_discrete_mathematics)
    <!-- 1. Described by .ppt ⊊ 👉「1.多重_·_辗转相除法_自动运行在「杜瓦瓶」=「纯反射∧无吸收の含缺口の黑体」中.pptx」 -->
    1. Described by .ppt ⊊ 👉[「1.『Multiple Euclidean algorithm』runs automatically in『Dewar bottle』=『pure-reflection non-absorbing notched blackbody』.pptx」](https://github.com/ChenZhu-Xie/geometric_optics_2_discrete_mathematics/raw/master/1.『多重·辗转相除法』自动运行在『杜瓦瓶』=『纯反射∧无吸收の含缺口の黑体』中.pptx)
    2. Utilizes simulator ⊷ 👉 [2D ray-optics simulation](https://github.com/ChenZhu-Xie/ray_optics__xcz)
        * Utilized by .ppt ⊶ 👉[「A_guided_tour_to_Ray_&_Wave_Optics_Simulation.pptx」](https://github.com/ChenZhu-Xie/ray_optics__xcz/raw/master/A_guided_tour_to_Ray_&_Wave_Optics_Simulation.pptx)
            * Links to model ✉ 👉 [NLAST-vector model (Private)](https://github.com/ChenZhu-Xie/NLAST_private)
                * Contains paper ⊋ 👉 [Berry-Mcleod paper (Private)](https://github.com/ChenZhu-Xie/Berry_Mcleod_paper__private)
                * 『Wave Optics』in『Partial Differential Equations (PDEs)』
    <!-- 3. Involved in book ⊊ 👉 [Ray & Wave Optics simulation](https://github.com/ChenZhu-Xie/geometric_optics_2_discrete_mathematics/master/1.多重_·_辗转相除法_自动运行在「杜瓦瓶」=「纯反射∧无吸收の含缺口の黑体」中.pptx) -->
    3. Involved in book ⊊ 👉 [Illusions_of_Illustrations_·_Zodiac](https://github.com/ChenZhu-Xie/3_books_with_cpp/tree/master/cpp_codes_for_book2『Illusions_of_Illustrations_·_Zodiac』)
        * Contained by books ⊂ 👉 [three e-books](https://github.com/ChenZhu-Xie/3_books_with_cpp)
    4. Belongs to Career ⊊ 👉 [PhD activities](https://github.com/ChenZhu-Xie/PhD_activities)
    5. Linked to ✉ 👉[「Penrose's room」that「cannot be illuminated by a single point」](https://www.bilibili.com/video/BV18p421d7NK)
* 中文「自述文档」㊥ 👉 [几何光学 in 离散数学](https://gitee.com/ChenZhu-Xie/geometric_optics_2_discrete_mathematics)

## Description
* 『This exploration process』is one of『the examples of the second book』
    * Using『Euclidean algorithm』to understand the『Multiple reflections』of light from the『Inner wall of the silver mirror』in the unsealed『Dewar bottle』
* Discussed the application of algebra (mathematics) in geometry (optics)
    * External light source: when it enters the『pure reflection blackbody』from the outside, the light will eventually come out from the gap. Why?
    * Internal light source: when the source is inside the『pure reflection blackbody』,light may not necessarily come out from the gap. What are the corresponding conditions?

## Inplementation
1. Ideological perspective: Abstract the『optical process』in『concave mirror』into『mathematical process』
    * See the animation in file「Multiple Euclidean algorithm runs automatically in『Dewar bottle』=『pure-reflection non-absorbing notched blackbody』.pptx」
    * See the content『The origin of the circular vector』on page 8 of[「2.『Illusions_of_Illustrations_·_Zodiac』.pdf」](https://github.com/ChenZhu-Xie/3_books_with_cpp/tree/master/2.『Illusions_of_Illustrations_·_Zodiac』(C++).pdf)
2. Optical Expansion:『Integral Sphere with Notches』➞『Maze with Exits』
    * The same conclusion applies to『any other shape』, such as a『labyrinth-shaped cavity』
    * That is to say, the shape of a blackbody may not necessarily be spherical
        * If the light source is『inside the maze』, the light『may not be able to solve/escape the maze』
        * See the case『[Maze solution](https://phydemo.app/ray-optics/cn/gallery/maze-solution)』
        * If the light source is『outside the maze』, then the light『can definitely come out of the maze again』
        * ![fig](https://raw.githubusercontent.com/ChenZhu-Xie/geometric_optics_2_discrete_mathematics/master/img/maze_1.1.png "What goes up, must come down.")
        * ![fig](https://raw.githubusercontent.com/ChenZhu-Xie/geometric_optics_2_discrete_mathematics/master/img/maze_2.1.png "What goes in, must come out.")
3. Mathematical Expansion:『Bivariate』to『Multivariate』linear indeterminate equation ('s Special/General solution)
    * Open the folder "[cpp_codes_for_book2『Illusions_of_Illustrations_·_Zodiac』](https://github.com/ChenZhu-Xie/3_books_with_cpp/tree/master/cpp_codes_for_book2『Illusions_of_Illustrations_·_Zodiac』)".
    * Run[「12.第10个程序的改良版(2+5+8b).cpp」](https://gitee.com/ChenZhu-Xie/3_books_with_cpp/tree/master/cpp_codes_for_book2『Illusions_of_Illustrations_·_Zodiac』/12.第10个程序的改良版(2+5+8b).cpp)inside using Visual C++ 6.0, or rather,
        * using `Microsoft Visual Studio C++ 6.0\Common\MSDev98\Bin\MSDEV.EXE`.
        * [VC6.0 Download & Setup](https://mp.weixin.qq.com/s/6YNbpj6RlCNh9zZd5K1wQA) ; Higher version of C++ is recommended, but may not be able to run this project?
    * [![fig](https://raw.githubusercontent.com/ChenZhu-Xie/geometric_optics_2_discrete_mathematics/master/img/book_2-6.png "『Multiple Euclidean algorithm』solve『Multivariate linear indeterminate equation』")](https://github.com/ChenZhu-Xie/geometric_optics_2_discrete_mathematics/blob/master/cpp_codes_for_book2%E3%80%8EIllusions_of_Illustrations_%C2%B7_Zodiac%E3%80%8F/12.%E7%AC%AC10%E4%B8%AA%E7%A8%8B%E5%BA%8F%E7%9A%84%E6%94%B9%E8%89%AF%E7%89%88(2%2B5%2B8b).cpp)
    * See page 10 of[「2.『Illusions_of_Illustrations_·_Zodiac』.pdf」](https://github.com/ChenZhu-Xie/3_books_with_cpp/tree/master/2.『Illusions_of_Illustrations_·_Zodiac』(C++).pdf)

## History
* This dive 👉 [『Geometric optics』in『Discrete mathematics』](https://github.com/ChenZhu-Xie/geometric_optics_2_discrete_mathematics)
    * (Personal time) 25-year_10-month-old
    * (Personal stage) Ph.D. 2nd Grade Winter Vacation (1.5 / 3.0)
    * (World time) 2024.02

<!-- ## Software Architecture
Software architecture description

## Installation

1.  xxxx
2.  xxxx
3.  xxxx

## Instructions

1.  xxxx
2.  xxxx
3.  xxxx

## Contribution

1.  Fork the repository
2.  Create Feat_xxx branch
3.  Commit your code
4.  Create Pull Request


## Gitee Feature

1.  You can use Readme\_XXX.md to support different languages, such as Readme\_en.md, Readme\_zh.md
2.  Gitee blog [blog.gitee.com](https://blog.gitee.com)
3.  Explore open source project [https://gitee.com/explore](https://gitee.com/explore)
4.  The most valuable open source project [GVP](https://gitee.com/gvp)
5.  The manual of Gitee [https://gitee.com/help](https://gitee.com/help)
6.  The most popular members  [https://gitee.com/gitee-stars/](https://gitee.com/gitee-stars/) -->
