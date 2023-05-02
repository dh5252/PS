# [Platinum III] 특별한 숙제 순서 바꾸기 - 27894 

[문제 링크](https://www.acmicpc.net/problem/27894) 

### 성능 요약

메모리: 2800 KB, 시간: 20 ms

### 분류

애드 혹

### 문제 설명

<p>Mr Singh은 NLCS Jeju의 선생님이다. Mr Singh은 현재 IB 과정 때문에 고통받는 12학년 학생들을 위해 수업 계획을 짜고 있다.</p>

<p>Mr Singh은 학생들이 받게 될 숙제의 순서인 숙제 계획을 짰다. 숙제 계획에는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개의 숙제가 있으며, 각 숙제에는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container> 이상 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container> 이하의 고유 번호가 부여된다.</p>

<p>선생님의 숙제 계획을 보고 분노한 학생들은 선생님에게 숙제 계획 요구안을 제시하였다.</p>

<p>Mr Singh은 학생들의 요구에 응하기로 하면서도, 커리큘럼을 망치고 싶지 않기 때문에, 다음 작업을 몇 번이든 실행하여 원래 숙제 계획을 요구안으로 바꿀 수 있는지 보고자 한다.</p>

<ul>
	<li><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c33"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>3</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$3$</span></mjx-container>개의 인접한 숙제를 선택하여 숙제 번호를 기준으로 오름차순 또는 내림차순으로 정렬한다.</li>
</ul>

<p>Mr Singh이 위 작업을 몇 번이든 반복하여 원래 숙제 계획을 요구안으로 바꿀 수 있는지 조사하는 프로그램을 작성하시오.</p>

### 입력 

 <p>입력의 첫 번째 줄에 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>이 주어진다.</p>

<p>입력의 두 번째 줄에 선생님의 원래 숙제 계획이 주어진다. <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개의 서로 다른 정수가 공백으로 구분되어 주어지며, 모든 정수는 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container> 이상 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container> 이하이다.</p>

<p>입력의 세 번째 줄에 학생들이 제시한 요구안이 두 번째 줄과 같은 형식으로 주어진다.</p>

### 출력 

 <p>첫 번째 줄에 Mr Singh이 위 작업을 몇 번이든 실행하여 원래 숙제 계획을 요구안으로 바꿀 수 있는지를 출력한다. 가능하면 <code>POSSIBLE</code>을, 불가능하면 <code>IMPOSSIBLE</code>을 출력한다. 대소문자에 유의한다.</p>

