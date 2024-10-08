#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 하노이의 탑 이동 과정을 저장할 벡터
vector<string> moves;

// 원판 이동 함수
void moveDisc(int n, char from, char to, char aux) {
    // 기저 조건: 원판이 1개일 때
    if (n == 1) {
        moves.push_back("원판 1을 " + string(1, from) + "에서 " + string(1, to) + "로 이동");
        return;
    }

    // 재귀 단계 1: n-1개의 원판을 보조 기둥으로 이동
    moveDisc(n - 1, from, aux, to);

    // 현재 원판을 목표 기둥으로 이동
    moves.push_back("원판 " + to_string(n) + "을 " + string(1, from) + "에서 " + string(1, to) + "로 이동");

    // 재귀 단계 2: n-1개의 원판을 보조 기둥에서 목표 기둥으로 이동
    moveDisc(n - 1, aux, to, from);
}

// 메인 함수
int main() {
    int n;
    cout << "원판의 개수를 입력하세요: ";
    cin >> n;

    // 하노이의 탑 풀이 시작
    moveDisc(n, 'A', 'C', 'B');

    // 이동 과정 출력
    cout << "하노이의 탑 이동 과정:" << endl;
    for (const auto& move : moves) {
        cout << move << endl;
    }
    cout << "하노이의 탑 최적 경로 : " << sizeof(moves) << endl;

    return 0;
}