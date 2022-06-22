
# Inha_Tutoring_DataStructure

&nbsp;&nbsp;이 레포지토리는 2022년 1학기에 진행된 인하대학교 자료구조 수업 튜터링 과제 목록과 풀이에 대한 레포지토리입니다. 튜터로 참여하였으며 튜티들은 다음과 같은 과제와 함께 튜터링을 받았습니다. 인하대학교에서 지원하는 각 과목에 대한 튜터링의 일환으로 튜티들에게 제공되는 과제들은 백준 문제풀이 사이트의 문제들과 그에 대한 선택적 풀이를 기본으로 하며, 필요한 경우 튜터에 의해 직접 제작한 문제들로 구성됩니다.

|Week|DataStructure|Assginment|
|:---:|:---:|:---:|
|1|[Array](#1주차-Array)|BOJ_1158|
|2|[Linked List](#2주차-Linked-List)|BOJ_1158, BOJ_2346|
|3|[Stack](#3주차-Stack)|BOJ_10828, BOJ_1935|
|4|[Queue](#4주차-Queue)|BOJ_18258, BOJ_1021|
|5|[Vector List Sequence](#5주차-Vector-List-Sequence)|자체문제(KOR) Vector Problem<br/>자체문제(KOR) Sequence Sample|
|6|[Tree](#6주차-Tree)|BOJ_11203, BOJ_13116|
|7|[Tree Traversal](#7주차-Tree-Traversal)|BOJ_1991<br/>중간고사 대비 질의|
|8|Mid-term||
|9<br/>10|[Priority Queue Heap](#9~10주차-Priority-Queue-Heap)|BOJ_1927, BOJ_2750, BOJ_2751|
|11|Binary Search Tree|BOJ_5639, BOJ_18240|
|12|Hash Table|BOJ_15829, BOJ_5525|
|13|Graph|BOJ_1260, BOJ_2667|
|14|Graph Traversal|BOJ_2606, BOJ_7576|
|14|Final||

---
## 1주차 Array
### 문제: [1158 요세푸스 문제](https://www.acmicpc.net/problem/1158)([샘플 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/INHA_Tutoring_DataStructure/Week01_Array_1158_BOJ.cpp))
&nbsp;&nbsp;특정 수 만큼 배열을 이동하며 요소를 방문하는 문제입니다. 추후에 접하게 될 큐(Queue)에서 순환형 배열을 접하게 되는데 이에 대한 예습 차원으로 선택하였습니다. 인덱스(Index) 관리의 기본적인 방식인 mod 연산을 사용하는 것을 연습합니다.<br/>


<br/><br/>
## 2주차 Linked List
&nbsp;&nbsp;자료구조 수업에서 배우는 연결 리스트(Linked List)는 2가지로, 단일 연결 리스트(Singly Linked-List)와 이중 연결 리스트(Doubly Linked-List)입니다. 둘 다 실습 수업에 포함되므로 아래의 문제를 통해 연습합니다. 두 문제 모두 두 가지의 연결 리스트를 이용하여 해결할 수 있으므로 두 문제에 대해 모두 연습하는 것을 추천합니다.

### 문제: [1158 요세푸스 문제](https://www.acmicpc.net/problem/1158) ( [샘플 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/INHA_Tutoring_DataStructure/Week02_Singly%20Linked-List_1158.cpp) )

&nbsp;&nbsp;1주차에도 포함되었던 이 문제는 일반적으로 큐나 배열을 이용해서 해결합니다. 그러나 리스트 또한 선형 자료구조이므로 사용해도 무관합니다. 샘플 코드는 단일 연결 리스트를 구현하여 푼 예제입니다.
<br/>

### 문제: [2346 풍선 터뜨리기](https://www.acmicpc.net/problem/2346) ([샘플 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/INHA_Tutoring_DataStructure/Week02_Singly%20Linked-List_1158.cpp))
&nbsp;&nbsp;이 문제는 앞선 '요세푸스 문제'의 상위 호환이라고 생각하시면 됩니다. 다만, 이중 연결 리스트를 구현하여 풀 경우 <b>메모리 초과</b>가 나타날 수 있습니다. 연습하는 데에 중점을 두도록 합니다. [(실제 문제의 정답 코드)](https://github.com/unsik6/BOJ_by_Cpp/blob/main/BaekJoon_CPlusPlus/BaekJoon_CPlusPlus/2346_BOJ.cpp)

<br/><br/>

## 3주차 Stack
### 문제: [10828 스택](https://www.acmicpc.net/problem/10828) ([샘플 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/INHA_Tutoring_DataStructure/Week03_Stack_10828_BOJ.cpp))
&nbsp;&nbsp;실제 출제되는 실습 문제와 동일한 유형의 문제입니다. 실제로 스택을 구현해보고 제시된 쿼리를 수행하면 됩니다. 제시된 쿼리는 수업 중 배우는 스택 ADT의 Method들과 거의 동일합니다. 샘플 코드는 배열로 구현되어 있습니다.

<br/>

### 문제: [1935 후위 표기식2](https://www.acmicpc.net/problem/1935)([샘플 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/INHA_Tutoring_DataStructure/Week03_Stack1935_BOJ.cpp)
&nbsp;&nbsp; 많은 학생들이 어려워하는 후위 표기식입니다. 후위 표기식을 입력 받으면 그 결과를 도출하는 것입니다. 실제로 해보면 크게 어렵지 않습니다. <b>실제 실습 문제에서는 중위 표기식을 후위 표기식으로 바꾸는 문제도 제시될 수 있습니다. 이 때, 괄호를 활용해야 하는 경우도 있습니다. 해당 문제는 [백준 1918 후위 표기식](https://www.acmicpc.net/problem/1918) 문제로 연습하시길 바랍니다.</b>

<br/><br/>
## 4주차 Queue
&nbsp;&nbsp; 
### 문제: [18258 큐2](https://www.acmicpc.net/problem/18258)([샘플 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/INHA_Tutoring_DataStructure/Week04_Queue_18258_BOJ.cpp))
&nbsp;&nbsp; 실제 출제되는 실습 문제와 동일한 유형의 문제입니다. 실제로 스택을 구현해보고 제시된 쿼리를 수행하면 됩니다. 제시된 쿼리는 수업 중 배우는 큐 ADT의 Method들과 거의 동일합니다. 샘플 코드는 순환형 배열로 구현되어 있습니다. 그리고 이 문제는 C 입력과 C++ 입력의 tie를 풀어줘야 됩니다.

<br/>

### 문제: [1021 회전하는 큐](https://www.acmicpc.net/problem/1021)([샘플 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/INHA_Tutoring_DataStructure/Week04_Queue_1021_BOJ.cpp))
&nbsp;&nbsp; 특별한 문제는 아닙니다. 위 18258를 풀 수 있다면 쉽게 풀 수 있는 문제입니다. 샘플 코드는 큐를 활용한 문제는 아닙니다. 다만, 문제에서 제시된 3가지 연산 모두 큐의 연산을 이용하여 구현할 수 있습니다.


<br/><br/>

## 5주차 Vector List Sequence
&nbsp;&nbsp;이 주제의 문제들은 따로 찾을 수가 없어서 별도로 만들었습니다. 문제에 오류가 있을 수 있습니다만,, 학부생이 급하게 만든 것이니 이해바랍니다 ㅠㅠ Vector 문제만 있습니다. List는 2주차에서 진행했으므로 만들지 않았고, 시간이 없어서 Sequence는 샘플 코드만 첨부하였습니다.
### 문제: [자체 Vector 문제](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/vector.pdf) ([샘플 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/INHA_Tutoring_DataStructure/Week05_Vector.cpp))
&nbsp;&nbsp; 실제 실습 문제와 유사한 유형으로 구성하였습니다. 오류가 있을 수도 있습니다.

<br/>

### [Sequence 샘플 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/INHA_Tutoring_DataStructure/Week05_Sequence.cpp)
&nbsp;&nbsp;언제 무슨 이유로 만들었는지 기억이 나지 않습니다. 참고 바랍니다.  범용성을 위해서 template를 이용하여 구현되어 있습니다.

<br/><br/>

## 6주차 Tree
&nbsp;&nbsp;tree 문제는 풀다 보니 binary tree 문제만 있다는 것을 깨달았습니다. 트리는 사이클이 없는 그래프라는 개념을 가지고 있습니다. 이에 따라 일반적인 트리 문제는 그래프 문제로 다뤄져서 일반 트리를 구현하면서 풀 수 있는 문제는 찾기가 어렵네요. 그래서 [제가 자료구조 수업 때 구현했던 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/INHA_Tutoring_DataStructure/Week06_winter_ds_treeProblemSolution.cpp)를 보시면서 구현 참고 바랍니다.

### 문제: [11203 ](https://www.acmicpc.net/problem/11203) ([샘플 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/INHA_Tutoring_DataStructure/Week06_Binary_Tree_11203_BOJ.cpp))
&nbsp;&nbsp; 공교롭게도 영어 문제입니다. 그렇게까지 어려운 난이도는 아니고 포화 이진 트리의 속성을 이용하는 문제입니다. 실제 Tree로 구현하는 경우 시간초과가 나타나는 것으로 알고 있습니다.  <b>많이 어려운 경우, [KTH 공식 솔루션](https://challenge.csc.kth.se/2014/solutions.pdf)의 A번째 문제를 보고 구현해보세요!</b>

<br/>

### 문제: [13116 30번 문제 ](https://www.acmicpc.net/problem/13116) ([샘플 코드]())
&nbsp;&nbsp; 위 문제와 마찬가지로 포화 이진 트리의 속성을 이용한 문제입니다. 크게 어렵진 않습니다.

<br/><br/>


## 7주차 Tree Traversal
&nbsp;&nbsp; 이 시기에는 중간고사를 대비해야 하는 주라 한 문제만 진행했었습니다.
### 문제: [1991 트리 순회]() ([샘플 코드](https://www.acmicpc.net/problem/1991))
&nbsp;&nbsp; 이진 트리가 주어지면 전위 순회, 중위 순회, 후위 순회의 결과를 출력합니다. 샘플 코드에서는 알파벳의 수 만큼 배열을 만들어서 트리로 구현했을 때 저장하게 될 인덱스를 부여했습니다. 실제로 입력 받은 이진 트리를 배열로 구현하면 너무 많은 용량을 차지하게 될 거라고 생각했기 때문입니다. 근데 또 튜터링 진행하면서 튜티 분들 코드 보니까 그렇지도 않습니다.

<br/><br/>

## 9~10주차 Priority Queue Heap
&nbsp;&nbsp; 1927 문제는 힙을 위한 문제이고, 2750은 정렬문제로 힙 정렬, 선택 정렬, 삽입 정렬을 연습할 수 있습니다. 선택 정렬과 삽입 정렬의 경우에도 실습 문제로 나타나니 꼭 연습하세요.

### 문제: [1927 최소 힙](https://www.acmicpc.net/problem/1927) ([샘플 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/INHA_Tutoring_DataStructure/Week08_1927_BOJ.cpp))
&nbsp;&nbsp; 대놓고 최소 힙을 구현하라는 문제입니다.

<br/>

### 문제: [2750 수 정렬하기](https://www.acmicpc.net/problem/2750) ([샘플 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/INHA_Tutoring_DataStructure/Week08_2750_BOJ.cpp))
&nbsp;&nbsp; O(n<sup>2</sup>) 수행 시간의 정렬 알고리즘을 연습하는 문제입니다. 수업 중 배우는 우선순위 큐에 대한 선택 정렬, 삽입 정렬에 해당합니다. 샘플 코드에는 버블 정렬, 삽입 정렬, 선택 정렬 순으로 구성되어 있습니다.

<br/>

### 문제: [2751 수 정렬하기2](https://www.acmicpc.net/problem/2751) ([샘플 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/INHA_Tutoring_DataStructure/Week08_2751_BOJ.cpp))
&nbsp;&nbsp; 위 2751 문제의 시리즈 문제입니다. 여기서는 O(nlogn) 수행 시간의 정렬 알고리즘을 연습합니다. 힙 정렬이 여기에 속합니다. 실제로 힙을 구현해서 푸시면 됩니다. 샘플 코드에는 힙 정렬, 합병 정렬 순으로 구성되어 있습니다.

<br/><br/>

## 주차 
### 문제: []() ([샘플 코드]())
&nbsp;&nbsp; 

<br/>

### 문제: []() ([샘플 코드]())
&nbsp;&nbsp; 

<br/><br/>

## 주차 
### 문제: []() ([샘플 코드]())
&nbsp;&nbsp; 

<br/>

### 문제: []() ([샘플 코드]())
&nbsp;&nbsp; 

<br/><br/>
