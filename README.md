# KAU_DS

📚 **KAU 소프트웨어학과 자료구조 실습 기반 개인 프로젝트**

이 저장소는 배열, 스택, 큐, 연결 리스트, 트리, 그래프 등 전형적인 자료구조를 직접 구현하고, 이를 기반으로 탐색 및 최단경로 알고리즘(DFS, BFS, Dijkstra, Prim 등)을 실습하는 공간입니다.  
Git Flow 기반의 브랜치 전략과 버전 관리, 이슈 및 마일스톤 기반 개발 흐름을 경험하는 데 목적이 있습니다.

---

## 🏗️ 프로젝트 구조

```
KAU_DS/
├── include/                # 헤더 파일
├── test/                   # 테스트 코드 (입력 예제 등)
├── docs/                   # 문서 및 설명 자료
├── README.md
├── .gitattributes
└── .gitignore
```

---

## 🔧 개발 환경

- **언어:** C++
- **플랫폼:** macOS / Linux / Windows
- **툴체인:** `g++`, `cmake` (or `make`)
- **IDE:** Visual Studio Code

---

## 🌱 Git 브랜치 전략

> Git Flow 기반 브랜치 전략을 따릅니다.

| 브랜치 | 설명 |
|--------|------|
| `main` | 최종 릴리스 버전 유지용 (절대 직접 커밋 금지) |
| `develop` | 통합 개발 브랜치 |
| `feature/<이슈번호>-<간단설명>` | 단위 기능 개발용 브랜치 |

```bash
# 브랜치 예시
feature/1-implement-stack
feature/2-queue-linkedlist
feature/5-dfs-adjacencylist
```

---

## 📌 커밋 메시지 규칙 (Conventional Commits)

```
Type: Subject

Body (선택)

Footer (선택, e.g., Closes #1)
```

### 타입 종류:

- `feat`: 새로운 기능
- `fix`: 버그 수정
- `docs`: 문서 관련 변경
- `refactor`: 리팩토링
- `test`: 테스트 관련
- `chore`: 설정 등 기타

### 예시:

```bash
feat: Implement stack using array

구조체 기반 배열 스택 구현 완료.
main()에서 간단한 push/pop 테스트 수행.

Closes #1
```

---

## 🔁 작업 흐름 예시

```bash
# develop 브랜치로 이동
git switch -c develop
git pull origin develop

# feature 브랜치 생성
git switch -c feature/1-implement-stack

# 작업, 커밋, 푸시
git add .
git commit -m "feat: Implement stack using array"
git push origin feature/1-implement-stack

# GitHub에서 Pull Request 생성 → develop으로 병합
```

---

## 🚀 마일스톤 예시

| 버전 | 내용 |
|------|------|
| `v0.1.0` | 스택 / 큐 / 연결 리스트 |
| `v0.2.0` | 그래프 기초 (인접 리스트 / 인접 행렬) |
| `v0.3.0` | DFS / BFS |
| `v0.4.0` | 최소 신장 트리 (Prim, Kruskal) |
| `v1.0.0` | 전체 알고리즘 및 테스트 완료 버전 |

---

## 📂 기능 구현 상태

| 기능 | 상태 |
|------|------|
| Linked List | ⏳ 진행 예정 |
| Stack | ⏳ 진행 예정 |
| Queue | ⏳ 진행 예정 |
| DFS | ⏳ 진행 예정 |
| BFS | ⏳ 진행 예정 |
| Prim / Dijkstra | ⏳ 진행 예정 |

---

## 🐛 이슈 관리 규칙

- 기능 개발 전 GitHub 이슈 생성
- 이슈에 `Type`, `Priority`, `Milestone` 라벨 할당
- 브랜치 및 커밋, PR과 이슈 연결 (`Closes #이슈번호`)

---

## 📦 Release

| 버전 | 날짜 | 설명 |
|------|------|------|
| v0.1.0 | - | 기초 자료구조 구현 |
| v0.2.0 | - | 그래프 기본 기능 구현 |
| v1.0.0 | - | 전체 알고리즘 기능 완료 |

---

## 📜 라이선스

본 프로젝트는 학습용이며 라이선스 없이 운영됩니다. 필요 시 MIT License를 명시할 수 있습니다.

---

## ✍️ 작성자

**김병진**  
- GitHub: [@TomorrowIppo](https://github.com/TomorrowIppo)  
- KAU 소프트웨어학과
