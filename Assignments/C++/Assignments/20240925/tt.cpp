#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

// 하노이의 탑 이동 과정을 저장할 벡터
vector<string> moves;

// 각 기둥을 표현하는 스택 (0: A 기둥, 1: B 기둥, 2: C 기둥)
stack<int> poles[3];

// 하노이의 탑 규칙 검사 함수
bool isValidMove(int from, int to) {
    // 출발 기둥이 비어있으면 이동할 원판이 없으므로 이동 불가
    if (poles[from].empty()) {
        return false;
    }

    // 목표 기둥이 비어있지 않은 경우, 이동하려는 원판이 목표 기둥의 맨 위 원판보다 크면 이동 불가
    if (!poles[to].empty() && poles[from].top() > poles[to].top()) {
        return false;
    }

    return true;
}

// 원판 이동 함수
void moveDisc(int n, int from, int to, int aux) {
    // 기저 조건: 이동할 원판이 1개일 때
    if (n == 1) 
    {
        if (isValidMove(from, to)) 
        {
            int disc = poles[from].top();
            poles[from].pop();
            poles[to].push(disc);
            moves.push_back("원판 " + to_string(disc) + "을 " + string(1, 'A' + from) + "에서 " + string(1, 'A' + to) + "로 이동");
        }
        return;
    }

    // 재귀 단계 1: n-1개의 원판을 보조 기둥으로 이동
    moveDisc(n - 1, from, aux, to);

    // 현재 원판을 목표 기둥으로 이동
    if (isValidMove(from, to)) {
        int disc = poles[from].top();
        poles[from].pop();
        poles[to].push(disc);
        moves.push_back("원판 " + to_string(disc) + "을 " + string(1, 'A' + from) + "에서 " + string(1, 'A' + to) + "로 이동");
    }

    // 재귀 단계 2: 보조 기둥의 n-1개 원판을 목표 기둥으로 이동
    moveDisc(n - 1, aux, to, from);
}

int main() {
    int n;
    cout << "원판의 개수를 입력하세요: ";
    cin >> n;

    int start, end;
    cout << "시작 기둥을 선택하세요 (0: A, 1: B, 2: C): ";
    cin >> start;
    cout << "목표 기둥을 선택하세요 (0: A, 1: B, 2: C): ";
    cin >> end;

    // 보조 기둥 결정
    int aux = 3 - start - end;

    // 초기 상태 설정: 모든 원판을 시작 기둥에 쌓음
    for (int i = n; i > 0; i--) {
        poles[start].push(i);
    }

    // 하노이의 탑 풀이 시작
    moveDisc(n, start, end, aux);

    // 이동 과정 출력
    cout << "하노이의 탑 이동 과정:" << endl;
    for (const auto& move : moves) {
        cout << move << endl;
    }
    cout << "총 이동 횟수: " << moves.size() << endl;

    return 0;
}