# 2026 KU Algorithm & Computer Science Study

~~[백준 그룹](https://www.acmicpc.net/group/25035)~~ *백준 섭종에 따라 2026.05.01부터 프로그래머스 문제로 대체합니다*

****

## 스터디 목표
- 기업 코딩 테스트 및 PCCP 자격증 취득을 위한 문제 해결 능력과 C++ 활용능력 향상 및 알고리즘 문제 유형화
- OOP, 디자인 패턴, 엔진 아키텍처 등 각자가 학습 중인 넓은 범위의 CS 지식을 자유롭게 공유
- 서로의 학습 진도와 개인 프로젝트 진행 상황을 나누며 긍정적인 자극과 동기부여

## 진행 방식
- **시간**: 매주 목요일 저녁 8시
- **장소**: 온라인 ([Discord](http://discordapp.com/users/806626814504075334))
- **내용**: 
  - 알고리즘 리뷰: 주차별로 지정된 알고리즘 문제에 대해 각자의 접근 방식, 막혔던 부분, 시공간 복잡도 등을 자유롭게 리뷰합니다.
  - 자유 기술 토크: 알고리즘 리뷰 후, 이번 주에 각자 공부했던 CS 개념, 개발 관련 지식, 혹은 흥미로운 기술 아티클 등을 가볍게 공유합니다.

## 디렉토리 구조 및 네이밍 컨벤션

저장소의 기본 구조는 `주차-주제/난이도-문제번호-문제이름/참여자이름/` 순서를 따릅니다.

- **폴더 및 파일명 규칙**: 띄어쓰기 대신 하이픈(`-`)을 사용합니다.
- **커밋 메시지 예제**: `작업유형: [주차] 난이도 문제번호 문제이름` 
  - Git 시스템이 커밋 작성자(Author)를 자동 추적하므로, 커밋 메시지에 본인 이름은 기재하지 않습니다.
  - 규칙을 엄격하게 따를 필요는 없으나, 가능하면 깔끔한 내용을 지향합니다.
  - **작업 유형 태그**:
    - `solve:` 초기 정답 코드 업로드
    - `docs:` 풀이 설명(README.md) 등 문서 추가 및 수정
    - `refactor:` 기존 코드 개선 및 최적화
    - 
  - *예시: `solve: [week02] 실1 1926 그림`*

### 구조 예시
```text
.
└── ku-algorithm-study/
    ├── week01-linear-ds/
    │   ├── 실4-10828-스택/
    │   │   ├── 헤파리/
    │   │   │   ├── solution.cpp
    │   │   │   └── README.md
    │   │   └── 다른참여자/
    │   └── ...
    ├── week02-bfs/
    │   └── 실1-1926-그림/
    │       └── ...
    └── ...
````

## 파일 작성 가이드 및 C++ 규칙

참여자 본인의 폴더(`.../참여자이름/`) 내부에는 정답 코드와 함께 자유로운 형태로 풀이 기록을 남겨주세요.

  - **필수**:
      - 문제 해결 코드 파일
  - **선택**:
      - 풀이 로직, 점화식, 시간/공간 복잡도를 정리한 마크다운 파일 (`README.md`)
      - 이해를 돕기 위한 도식, 순서도 이미지 등

-----

## 알고리즘 스터디 로그

| 주차 | 진행 기간 | 학습 주제 | 대표 유형 |
| :--: | :-- | :--: | :--: |
| **1주차** | `26.04.03 ~ 26.04.09` | **선형 자료구조**<br>(Vector, List, Stack, Queue, Deque) | 괄호 쌍 체크, 에디터(커서 이동) |
| **2주차** | `26.04.10 ~ 26.04.16` | **BFS**<br>(Queue, Pair) | Flood Fill, 격자 내 최단 거리 |
| 중간고사 |  |  |  |
| **3주차** | `26.04.17 ~ 26.04.30` | **DFS와 재귀 & OOP기초와 디자인패턴**<br>(Stack, base case, Observer/Command/Singleton) | D&C, 트리순회, 프랙탈 |
| **4주차** | `26.05.01 ~ 26.05.07` | **백트래킹**<br>(state array, call stack) | [순열/조합](https://school.programmers.co.kr/learn/courses/30/lessons/87946?language=cpp), [2차원 가지치기](https://school.programmers.co.kr/learn/courses/30/lessons/12952?language=cpp), [상태분기](https://school.programmers.co.kr/learn/courses/30/lessons/92342?language=cpp) |
| **5주차** | `26.05.08 ~ 26.05.14` | **DP (동적 계획법)**<br>(Memoization, 점화식) | [1차원](https://school.programmers.co.kr/learn/courses/30/lessons/12914?language=cpp), [2차원](https://school.programmers.co.kr/learn/courses/30/lessons/12913?language=cpp), [경로 누적 최적화](https://school.programmers.co.kr/learn/courses/30/lessons/43105?language=cpp) |
| 외부행사 |  |  |  |
| **6주차** | `26.05.15 ~ 26.05.28` | **Dijkstra (다익스트라)**<br>(priority queue, edge relaxation) | [기본](https://school.programmers.co.kr/learn/courses/30/lessons/12978?language=cpp), [최적화](https://school.programmers.co.kr/learn/courses/30/lessons/72413?language=cpp), [Multi-Source](https://school.programmers.co.kr/learn/courses/30/lessons/118669), |
| **7주차** | `26.05.28 ~ 26.06.04` | **Dijkstra 심화** | [3차원](https://school.programmers.co.kr/learn/courses/30/lessons/67259), [가중치 1](https://school.programmers.co.kr/learn/courses/30/lessons/132266), [추상화](https://school.programmers.co.kr/learn/courses/30/lessons/118668), [동적/비트마스킹](https://school.programmers.co.kr/learn/courses/30/lessons/81304)|
| **8주차** | `26.06.04 ~ 26.06.11` | |  | 
