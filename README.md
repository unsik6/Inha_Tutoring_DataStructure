# Inha_Tutoring_DataStructure

&nbsp;&nbsp;이 레포지토리는 2022년 1학기에 진행된 인하대학교 자료구조 수업 튜터링에서 활용한 과제 목록과 풀이에 대한 레포지토리입니다. 필자는 튜터로 참여하였으며 튜티들은 다음과 같은 과제와 함께 튜터링을 받았습니다. 과제들은 백준 문제풀이 사이트의 문제들을 활용하였으며 그에 대한 전체 풀이를 기본으로 하며, 필요한 경우 백준 문제를 부분적으로 풀거나 튜터에 의해 직접 제작한 문제들을 활용하였습니다.

- 실제로 자료구조 실습 문제는 아래의 문제들보다 훨씬 난이도가 쉽습니다. 자료구조 실습을 준비하면서 문제 풀이에 대한 접근과 도움이 될 수도 있는 정보들을 종합적으로 전달하려고 하다 보니 선택된 문제들의 수준이 실제 자료구조 수업의 실습 문제보다 어려울 수 있습니다.
- 자료구조 수업에서의 실습 점수의 향상만 원하는 경우에는 각 수업의 조교님들께서 배포하시는 실습 강의 자료만 가지고 공부하거나 족보를 찾아보시길 바랍니다. 이 레포지토리에서는 <b>저작권으로 인하여 지난 자료구조의 실습 문제 및 강의 자료는 포함하고 있지 않습니다.</b> 다만, 제가 해당 문제를 보고 작성한 소스코드는 일부 포함되어 있습니다.
- <b>저는 코딩을 잘 못합니다.</b> 또한, 문제들의 '샘플 코드'들은 제가 백준 문제를 처음 접했을 당시에 작성한 코드가 대부분이라 더욱 질이 좋지 못합니다. 참고용으로만 사용하시길 바랍니다.
- <b>저는 전문가가 아닙니다.</b> 어떤 문제들이 여러분께 더 도움이 되는지 그런 것도 잘 모르고, 저도 학부생이라 바쁘기 때문에 아래의 텍스트들이 잘못 되어있거나 설명이 부족할 수 있습니다.
- 오류가 있거나 수정이 필요 조언을 해주실 부분이 있으시다면 tlsguswns1196xx@gmail.com으로 메일 부탁드립니다.

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
|9<br/>10|[Priority queue Heap](#9-10주차-Priority-queue-Heap)|BOJ_1927, BOJ_2750, BOJ_2751|
|11|[Binary Search Tree](#11주차-Binary-Search-Tree)|BOJ_5639, BOJ_18240|
|12|[Hash table](#12주차-Hash-table)|BOJ_15829, BOJ_5525|
|13|[Graph](#13주차-Graph)|BOJ_1260, BOJ_2667|
|14|[Graph Traversal](#14주차-Graph-Traversal)|BOJ_2606, BOJ_7576|
|14|Final||

---
## 1주차 Array
### 문제: [1158 요세푸스 문제 (실버4)](https://www.acmicpc.net/problem/1158) ([샘플 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/Week01_Array_1158_BOJ.cpp))
&nbsp;&nbsp;특정 수 만큼 배열 안에서 이동하며 요소를 방문하는 문제입니다. 추후에 접하게 될 큐(Queue)에서 순환형 배열을 접하게 되는데 이에 대한 예습 차원으로 선택하였습니다. 인덱스(Index) 관리의 기본적인 방식인 mod 연산을 사용하는 것을 연습합니다.<br/>


<br/><br/>
## 2주차 Linked List
&nbsp;&nbsp;자료구조 수업에서 배우는 연결 리스트(Linked List)는 2가지로, 단일 연결 리스트(Singly Linked-List)와 이중 연결 리스트(Doubly Linked-List)입니다. 둘 다 실습 수업에 포함되므로 아래의 문제를 통해 연습합니다. 두 문제 모두 두 가지의 연결 리스트를 이용하여 해결할 수 있으므로 두 문제에 대해 모두 연습하는 것을 추천합니다.

### 문제: [1158 요세푸스 문제 (실버4)](https://www.acmicpc.net/problem/1158) ([샘플 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/Week01_Array_1158_BOJ.cpp))

&nbsp;&nbsp;1주차에도 포함되었던 이 문제는 일반적으로 큐나 배열을 이용해서 해결합니다. 그러나 리스트 또한 선형 자료구조이므로 사용해도 무관합니다. 샘플 코드는 단일 연결 리스트를 구현하여 푼 예제입니다.
<br/>

### 문제: [2346 풍선 터뜨리기 (실버3)](https://www.acmicpc.net/problem/2346) ([샘플 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/Week02_Doubly_Linked_List_2346_BOJ.cpp))
&nbsp;&nbsp;이 문제는 앞선 '요세푸스 문제'의 상위 호환이라고 생각하시면 됩니다. 샘플 코드는 이중 연결 리스트로 구현되어 있습니다. 다만, 이중 연결 리스트를 구현하여 풀 경우 <b>메모리 초과</b>가 나타날 수 있습니다. 연습하는 데에 중점을 두도록 합니다. [(실제 문제의 정답 코드)](https://github.com/unsik6/BOJ_by_Cpp/blob/main/BaekJoon_CPlusPlus/BaekJoon_CPlusPlus/2346_BOJ.cpp)

<br/><br/>

## 3주차 Stack
### 문제: [10828 스택 (실버4)](https://www.acmicpc.net/problem/10828) ([샘플 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/Week03_Stack_10828_BOJ.cpp))
&nbsp;&nbsp;실제 출제되는 실습 문제와 동일한 유형의 문제입니다. 실제로 스택을 구현해보고 제시된 쿼리를 수행하면 됩니다. 제시된 쿼리는 수업 중 배우는 스택 ADT의 Method들과 거의 동일합니다. 샘플 코드는 배열로 구현되어 있습니다.

<br/>

### 문제: [1935 후위 표기식2 (실버3)](https://www.acmicpc.net/problem/1935) ([샘플 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/Week03_Stack_1935_BOJ.cpp))
&nbsp;&nbsp; 많은 학생들이 어려워하는 후위 표기식입니다. 후위 표기식을 입력 받으면 그 결과를 도출하는 것입니다. 실제로 해보면 크게 어렵지 않습니다. <b>실제 실습 문제에서는 중위 표기식을 후위 표기식으로 바꾸는 문제도 제시될 수 있습니다. 이 때, 괄호를 활용해야 하는 경우도 있습니다. 해당 문제는 [백준 1918 후위 표기식](https://www.acmicpc.net/problem/1918) 문제로 연습하시길 바랍니다.([1918 풀이 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/Week03_Stack_1918_BOJ.cpp))</b>

<br/><br/>
## 4주차 Queue
&nbsp;&nbsp; 
### 문제: [18258 큐2 (실버4)](https://www.acmicpc.net/problem/18258) ([샘플 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/Week04_Queue_18258_BOJ.cpp))
&nbsp;&nbsp; 실제 출제되는 실습 문제와 동일한 유형의 문제입니다. 실제로 큐을 구현해보고 제시된 쿼리를 수행하면 됩니다. 제시된 쿼리는 수업 중 배우는 큐 ADT의 Method들과 거의 동일합니다. 샘플 코드는 순환형 배열로 구현되어 있습니다. 그리고 이 문제는 C 입력과 C++ 입력의 tie를 풀어줘야 됩니다.

<br/>

### 문제: [1021 회전하는 큐 (실버4)](https://www.acmicpc.net/problem/1021) ([샘플 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/Week04_Queue_1021_BOJ.cpp))
&nbsp;&nbsp; 특별한 문제는 아닙니다. 위 18258를 풀 수 있다면 쉽게 풀 수 있는 문제입니다. 샘플 코드는 큐를 활용한 문제는 아닙니다. 다만, 문제에서 제시된 3가지 연산 모두 큐의 연산을 이용하여 구현할 수 있습니다.


<br/><br/>

## 5주차 Vector List Sequence
&nbsp;&nbsp;이 주제의 문제들은 따로 찾을 수가 없어서 별도로 만들었습니다. 문제에 오류가 있을 수 있습니다만,, 학부생이 급하게 만든 것이니 이해바랍니다 ㅠㅠ Vector 문제만 있습니다. List는 2주차에서 진행했으므로 만들지 않았고, 시간이 없어서 Sequence는 샘플 코드만 첨부하였습니다.
### 문제: [자체 Vector 문제](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/Week05_Vector_problem.pdf) ([샘플 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/Week05_Vector.cpp))
&nbsp;&nbsp; 실제 실습 문제와 유사한 유형으로 구성하였습니다. 오류가 있을 수도 있습니다.

<br/>

### [Sequence 샘플 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/Week05_Sequence.cpp)
&nbsp;&nbsp;언제 무슨 이유로 만들었는지 기억이 나지 않습니다. 아마 자료구조 수업 들으면서 작성한 코드였던 걸로 기억합니다. 참고 바랍니다.  범용성을 위해서 template를 이용하여 구현되어 있습니다.

<br/><br/>

## 6주차 Tree
&nbsp;&nbsp;Tree 문제는 풀다 보니 준비한 문제가 binary tree 문제만 있다는 것을 깨달았습니다. 트리는 사이클이 없는 그래프라는 개념을 가지고 있습니다. 이에 따라 일반적인 트리 문제는 그래프 문제로 다뤄져서 일반 트리를 구현해야 풀 수 있는 문제는 찾기가 어렵네요. 그래서 [제가 자료구조 수업 때 구현했던 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/Week06_winter_ds_treeProblemSolution.cpp)를 보시면서 구현 참고 바랍니다.

### 문제: [11203 Numbers On a Tree (실버5)](https://www.acmicpc.net/problem/11203) ([샘플 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/Week06_Binary_Tree_11203_BOJ.cpp))
&nbsp;&nbsp; 공교롭게도 영어 문제입니다. 그렇게까지 어려운 난이도는 아니고 포화 이진 트리의 속성을 이용하는 문제입니다. 실제 Tree로 구현하는 경우 시간초과가 나타나는 것으로 알고 있습니다.  <b>많이 어려운 경우, [KTH 공식 솔루션](https://challenge.csc.kth.se/2014/solutions.pdf)의 A번째 문제를 보고 구현해보세요!</b>

<br/>

### 문제: [13116 30번 문제 (실버4)](https://www.acmicpc.net/problem/13116) ([샘플 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/Week06_Binary_Tree_13116_BOJ.cpp))
&nbsp;&nbsp; 위 문제와 마찬가지로 포화 이진 트리의 속성을 이용한 문제입니다. 크게 어렵진 않습니다.

<br/><br/>


## 7주차 Tree Traversal
&nbsp;&nbsp; 이 시기에는 중간고사를 대비해야 하는 주라 한 문제만 진행했었습니다.
### 문제: [1991 트리 순회 (실버1)](https://www.acmicpc.net/problem/1991) ([샘플 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/Week07_Tree_Traversal_1991_BOJ.cpp))
&nbsp;&nbsp; 이진 트리가 주어지면 전위 순회, 중위 순회, 후위 순회의 결과를 출력합니다. 샘플 코드에서는 알파벳의 수 만큼 배열을 만들어서 트리로 구현했을 때 해당하는 알파벳이 저장될 인덱스를 부여했습니다. 예를 들면 입력된 이진트리를 실제 배열로 구현했을 때 A가 위치하는 인덱스가 1이라면 만든 배열의 'A'에 해당하는 요소에 들어 있는 값이 1이 됩니다. 실제로 입력 받은 이진 트리를 배열로 구현하면 너무 많은 용량을 차지하게 될 거라고 생각했기 때문에 앞서 말씀드린 방식을 고려했습니다. 근데 또 튜터링 진행하면서 튜티 분들 코드 보니까 그렇지도 않습니다.

<br/><br/>

## 9 10주차 Priority queue Heap
&nbsp;&nbsp; 1927 문제는 힙을 위한 문제이고, 2750과 2751은 정렬문제로 힙 정렬, 선택 정렬, 삽입 정렬을 연습할 수 있습니다. 선택 정렬과 삽입 정렬의 경우에도 실습 문제로 나타나니 꼭 연습하세요.

### 문제: [1927 최소 힙 (실버2)](https://www.acmicpc.net/problem/1927) ([샘플 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/Week08_1927_BOJ.cpp))
&nbsp;&nbsp; 대놓고 최소 힙을 구현하라는 문제입니다.

<br/>

### 문제: [2750 수 정렬하기 (브론즈2)](https://www.acmicpc.net/problem/2750) ([샘플 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/Week08_2750_BOJ.cpp))
&nbsp;&nbsp; O(n<sup>2</sup>) 수행 시간의 정렬 알고리즘을 연습하는 문제입니다. 수업 중 배우는 우선순위 큐에 대한 선택 정렬, 삽입 정렬에 해당합니다. 샘플 코드에는 버블 정렬, 삽입 정렬, 선택 정렬 순으로 구성되어 있습니다.

<br/>

### 문제: [2751 수 정렬하기2 (실버5)](https://www.acmicpc.net/problem/2751) ([샘플 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/Week08_2751_BOJ.cpp))
&nbsp;&nbsp; 위 2750 문제의 시리즈 문제입니다. 여기서는 O(nlogn) 수행 시간의 정렬 알고리즘을 연습합니다. 힙 정렬이 여기에 속합니다. 실제로 힙을 구현해서 푸시면 됩니다. 샘플 코드에는 힙 정렬, 합병 정렬 순으로 구성되어 있습니다.

<br/><br/>

## 11주차 Binary Search Tree
&nbsp;&nbsp;이진 탐색 트리(Binary Search Tree, BST)는 자료구조 시간에 배우는 AVL tree 외에도 알고리즘 시간에 Red-Black tree를 배우게 되므로 꼭 구현해보시길 바랍니다.

### 문제: [5639 이진 검색 트리 (골드5)](https://www.acmicpc.net/problem/5639) ([샘플 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/Week11_5639_BOJ.cpp))
&nbsp;&nbsp; BST의 노드 프로퍼티를 잘 생각해보면 BST를 구현하는 것만으로 매우 쉽게 풀 수 있는 문제입니다.

<br/>

### 문제: [18240 이진 탐색 트리 복원하기 (골드2)](https://www.acmicpc.net/problem/18240) ([샘플 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/Week11_18240_BOJ.cpp))
&nbsp;&nbsp; <b>스페셜 저지</b> 문제입니다. 스페셜 저지란 정답이 1개 이상인 경우로 문제에서 제시된 조건만 충족하면 됩니다. 선택사항의 문제라고 생각하시면 되고 풀어보시되 정 안 되면 코드를 보시길 바랍니다. 저 같은 경우에도 트리의 모든 노드에 넘버링까지는 완성했으나 메모리 부족이 떠서 시간 관계상 인터넷에서 참고한 코드로 작성하였습니다.

<br/><br/>

## 12주차 Hash table
&nbsp;&nbsp; 해시 테이블(Hash table)의 경우에는 실제 실습 문제에 해시 함수가 주어져 있습니다. 그리고 아래의 문제들에는 없지만  해시 충돌 처리를 하는 문제도 실습 문제로 출제됩니다. 아래 문제들은 아주 기본적인 해싱입니다.

### 문제: [15829 Hashing (브론즈2)](https://www.acmicpc.net/problem/15829) ([샘플 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/Week12_15829_BOJ.cpp))
&nbsp;&nbsp; 주어진 prime number를 통해 Hash value를 구하는 문제입니다. 조금 다른 점이 있다면 자릿수의 거듭제곱을 곱해준다는 점이 있습니다. 이 문제에서는 Hash value만 구하지만 우리가 배우는 Hash table은 이 Hash value를 인덱스로 하여 실제 데이터들을 분류하여 저장하는 것까지 포함됩니다. 이 문제는 해싱을 하는 기본적인 개념을 익히기도 좋고, 앞으로 문제풀이를 하시면서 "어떤 자료형을 선택할지" 고민하는 것과 modular 연산의 법칙을 익힐 수 있어서 선택했습니다.  만약 문제를 푸시다가 계속해서 WA(wrong answer)가 나오면 이 [링크](https://sskl660.tistory.com/75)를 먼저 읽어보시길 바랍니다.

<br/>

### 문제: [5525 IOIOI (실버1)](https://www.acmicpc.net/problem/5525) ([샘플 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/Week12_5525_BOJ.cpp))
&nbsp;&nbsp; <b>이 문제는 안 풀어도 됩니다. 설명도 읽지 않으셔도 됩니다.</b> 문자열이 일치하는지 탐색하는 알고리즘 중  Rabin-Karp 알고리즘이라는 것이 있습니다. 이 알고리즘은 어떤 문자열 <i>S</i>에서 내가 찾고자 하는 문자열 <i>P</i>와 일치하는 부분을 찾는 문자열 매칭 알고리즘 중 하나로 해싱을 기반으로 하고 있습니다.  문자열 <i>S</i>에서 <i>|P|</i> 길이를 갖는 모든 부분 문자열에 대하여 정해진 해시 함수를 통해 계산한 해시값을 배열(hashArr)에 저장합니다. <i>{hashArr[i] = S[i]부터 S[i+|P|-1]까지의 부분문자열의 해시값}</i> 그리고 P에 대한 해시값(h_p)도 계산합니다. hashArr를 탐색하면서 h_p와 일치하는 경우, 해당하는 <i>S</i>의 부분 문자열과 <i>P</i>를 Naive하게 비교하여 계산합니다. (비교적 자세한 내용은 샘플 코드 확인)
  이 알고리즘은 실제로 <i>P</i>가 <i>S</i>에 나타날 확률이 적음을 이용했습니다. 즉, <i>P</i>와 <i>S</i>의 해시값이 다를 확률이 매우 높기 때문에 모든 부분문자열에 대해 하나하나 비교할 필요가 없고 해시값이 같은 경우에만 비교하면 됩니다. 해시값이 같을 때 직접 비교해서 맞는지 확인하는 이유는 해시값이 같더라도 우리가 수업 중에 배우는 해시 충돌의 가능성이 있기 때문입니다. 
<br/>&nbsp;&nbsp; Rabin-Karp로 이 문제를 Rabin-Karp 알고리즘으로 풀 경우 50점만 맞고 나머지 50점(인풋이 더 큰 경우)에는 시간초과가 나타납니다. 여러분에게 주어진 과제는 50점 + 시간초과를 띄우는 것입니다.

추가: 물론 이 문제는 입력 문자열이 매우 쉬운 구조를 가지고 있기 때문에 입력 문자열의 모든 문자를 단 한번만 확인해서 풀 수 있습니다. 더 빠르게 풀 수도 있구요. 저는 바빠서 그냥 대충 풀었습니다.([문제풀이 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/Week12_5525_BOJ_Solving.cpp))

<br/><br/>

## 13주차 Graph
&nbsp;&nbsp; 실제 그래프(Graph) 실습 문제는 수업 중에 배우는 간선 리스트(Edge List), 인접 리스트(Adjacency List) 또는 인접 행렬(Adjacency Matrix)를 구현하는 문제입니다. 그런데 이 문제를 따로 찾을 수가 없어요! 그래서 이론 진도 상 DFS와 BFS까지 진행되었었기 때문에 DFS와 BFS 문제를 풀면서 익히게 했습니다.  (그래프 표현방법에 대한 코드는 제가 자료구조 수업과 알고리즘 수업 때 구현했던 코드를 참고하시길 바랍니다. 인접 리스트의 경우 다른 알고리즘 구현을 위해 작성한 것에서 불필요한 부분을 다 잘라내서 참고하실 만한 것이 없으실 거에요... [인접 행렬](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/Week13_Adjacency_Matrix_sample.cpp), [인접 리스트](https://github.com/unsik6/Algorithms_Codes/tree/main/02_Data_Structures/04_Graph/01_Representations/01_AdjacencyList) )

### 문제: [1260 DFS와 BFS (실버2)](https://www.acmicpc.net/problem/1260) ([샘플 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/INHA_Tutoring_DataStructure/Week13_1260_BOJ.cpp))
&nbsp;&nbsp; BFS와 DFS 모두 구현하는 문제입니다. BFS와 DFS는 둘다 iterative하게 구현할 수 있고, DFS는 recursive하게도 구현할 수 있습니다. 제 기억 상으로는 자료구조에서는 recursive하게 구현하는 것을 배우므로 여러분은 굳이 iterative하게 구현하실 필요는 없습니다.

<br/>

### 문제: [2667 단지 번호 붙이기 (실버1)](https://www.acmicpc.net/problem/2667) ([샘플 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/Week13_2667_BOJ.cpp))
&nbsp;&nbsp; BFS와 DFS 둘 중 하나로 풀 수 있습니다. 제가 올려 드린 소스코드는 BFS로 푼 경우입니다. DFS로도 푸시기 바랍니다.

<br/><br/>

## 14주차 Graph Traversal
&nbsp;&nbsp; DFS와 BFS 문제만 출제 되는 것으로 알고 있습니다.
### 문제: [2606 바이러스 (실버3)](https://www.acmicpc.net/problem/2606) ([샘플 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/Week14_2606_BOJ.cpp))
&nbsp;&nbsp; 매우 유명한 유형의 그래프 순회문제입니다. DFS와 BFS, 둘다로 한번씩 풀어보세요. 그래프 표현방법은 편하신대로 진행하시면 됩니다.

<br/>

### 문제: [7576 토마토 (골드5)](https://www.acmicpc.net/problem/7576) ([샘플 코드](https://github.com/unsik6/Inha_Tutoring_DataStructure/blob/main/INHA_Tutoring_DataStructure/Week14_7576_BOJ.cpp))
&nbsp;&nbsp; 위의 '바이러스' 문제와 유사한 유형의 그래프 문제로 매우 유명한 시리즈 문제입니다. 그중 가장 쉬운 2차원 토마토 문제입니다. 위 문제와 푸는 방법이 크게 다르지 않습니다. 다만, DFS와 BFS 중 하나만 이용해서 풀 수 있습니다.

<br/><br/>
