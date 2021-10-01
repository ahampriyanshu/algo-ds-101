#include <bits/stdc++.h>
using std::vector;
using std::tuple;

/*
 * Take out adding\removing logic into separate class.
 * It provides functions to add and remove numbers from
 * our structure, while maintaining cnt[] and current_answer.
 * 
 */
struct Mo
{
    static constexpr int MAX_VALUE = 1005000;
    vector<long long> cnt;
    long long current_answer;

    void process(int number, int delta)
    {
        current_answer -= cnt[number] * cnt[number] * number;
        cnt[number] += delta;
        current_answer += cnt[number] * cnt[number] * number;
    }
public:
    Mo()
    {
        cnt = vector<long long>(MAX_VALUE, 0);
        current_answer = 0;
    }

    long long get_answer() const
    {
        return current_answer;
    }

    void add(int number)
    {
        process(number, 1);
    }

    void remove(int number)
    {
        process(number, -1);
    }
};

int main()
{
    int N, Q, BLOCK_SIZE;
    std::cin.sync_with_stdio(false);
    std::cin >> N >> Q;
    BLOCK_SIZE = static_cast<int>(sqrt(N));

    // No global variables, everything inside.
    vector<int> arr(N);
    vector<long long> answers(Q);
    vector< tuple<int, int, int> > queries;
    queries.reserve(Q);

    for(int i = 0; i < N; i++)
        std::cin >> arr[i];

    for(int i = 0; i < Q; i++) {
        int le, rg;
        std::cin >> le >> rg;
        queries.emplace_back(le, rg, i);
    }

    // Comparator as a lambda-function, which catches BLOCK_SIZE
    // from the above definition.
    auto mo_cmp = [BLOCK_SIZE](const tuple<int, int, int> &x,
            const tuple<int, int, int> &y) -> bool {
        int block_x = std::get<0>(x) / BLOCK_SIZE;
        int block_y = std::get<0>(y) / BLOCK_SIZE;
        if(block_x != block_y)
            return block_x < block_y;
        return std::get<1>(x) < std::get<1>(y);
    };

    std::sort(queries.begin(), queries.end(), mo_cmp);

    Mo solver;
    int mo_left = 0, mo_right = -1;

    // Usual Mo's algorithm stuff.
    for(const auto &q: queries) {
        int left, right, answer_idx;
        std::tie(left, right, answer_idx) = q;

        while(mo_right < right) {
            mo_right++;
            solver.add(arr[mo_right]);
        }
        while(mo_right > right) {
            solver.remove(arr[mo_right]);
            mo_right--;
        }

        while(mo_left < left) {
            solver.remove(arr[mo_left]);
            mo_left++;
        }
        while(mo_left > left) {
            mo_left--;
            solver.add(arr[mo_left]);
        }

        answers[answer_idx] = solver.get_answer();
    }

    for(int i = 0; i < Q; i++)
        std::cout << answers[i] << "\n";
    return 0;
}
