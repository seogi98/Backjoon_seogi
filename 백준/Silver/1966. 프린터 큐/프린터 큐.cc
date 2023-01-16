#include <iostream>
#include <queue>
#include <vector>
using namespace std;
 
typedef struct NODE {
    int docu_num;
    int rank;
}NODE;
 
queue<NODE*> rank_queue;
int docu_num, find_docu_num, print_order = 0, isFind = 0, max_num ;
NODE** rank_arr;
vector<int> answer;
 
int findMax() { 
    max_num = 0; 
    int max = rank_arr[0]->rank;
    // 최대값 찾기
    for (int j = 1; j < docu_num; j++) {
        if (max < rank_arr[j]->rank) max = rank_arr[j]->rank;
    }
    // max 를 -1으로 메꿔버리기 
    for (int j = 0; j < docu_num; j++) {
        if (max == rank_arr[j]->rank) {
            rank_arr[j]->rank = -1;
            max_num++;
        } 
    }
    return max;
}
 
int main(){
    int test_case;
    cin >> test_case;
 
    for (int i = 0; i < test_case; i++) {
        print_order = 0; 
        cin >> docu_num >> find_docu_num; 
        rank_arr = (NODE**)malloc(sizeof(NODE*)*docu_num);
         
        // 큐 초기화   
        while (rank_queue.size()) rank_queue.pop();
 
        for (int j = 0; j < docu_num; j++){
            rank_arr[j] = (NODE*)malloc(sizeof(NODE)*docu_num);
            rank_arr[j]->docu_num = j;
            cin >> rank_arr[j]->rank;
 
            NODE* sub_node = (NODE*)malloc(sizeof(NODE)*docu_num);
            sub_node->docu_num = j;
            sub_node->rank = rank_arr[j]->rank;
            rank_queue.push(sub_node);
        }
 
        isFind = 0; 
 
        while (!isFind) {
            // 최대값 찾기 
            int sub_max = findMax();
            // 최대값인 놈들을 출력해준다. 
            int sub_queue_size = rank_queue.size(); 
 
            // 큐 1바퀴 
            for (int j = 0; j < sub_queue_size; j++) {
                // 받아서 비교하기 
                NODE* sub_node = rank_queue.front();
 
                // 최대 값이 뒤에 없으면 
                if (max_num == 0) {
                    // 만약 현재 노드가 값이 최대값과 같고, 목적 노드라면 
                    if (sub_node->docu_num == find_docu_num && sub_node->rank == max_num) {
                        print_order++;
                        isFind = 1;
                        break;
                    }
                    // 아니면 
                    else {
                        break;
                    } 
                }
                // 제거 
                rank_queue.pop();
 
                // 만약 최대값과 랭크가 같으면 
                if (sub_node->rank == sub_max) {
                    // 찾고자 하는 index가 맞는지 확인 
                    // 맞으면 정답이다 !! 
                    if (sub_node->docu_num == find_docu_num) {
                        print_order++;
                        isFind = 1;
                        break;
                    }
                    // 틀리면 
                    else { 
                        print_order++;
                        max_num--;
                    }
                }
                else {
                    rank_queue.push(sub_node); 
                }
            }
 
        }
        answer.push_back(print_order);
    } 
 
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << "\n";
    } 
    return 0; 
}
