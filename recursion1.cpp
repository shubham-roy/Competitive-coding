#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef pair<int,int> pii;
typedef long long ll;

void subsetSearch(int i, vector<int>& arr, vector<int>& subset, vector<vector<int>>& subsets) {
    int n =  arr.size();
    if (i == n){
        subsets.push_back(subset);
        return;
    }

    // exclude
    subsetSearch(i+1,arr,subset,subsets);

    // include
    subset.push_back(arr[i]);
    subsetSearch(i+1,arr,subset,subsets);

    subset.pop_back();
    return;
}

void permutationSearch(vector<int>& arr, vector<bool>& vis, vector<int>& permutation, vector<vector<int>>& permutations) {
    int n = arr.size();
    if (permutation.size() == n){
        permutations.push_back(permutation);
        return;
    }

    for (int j = 0; j < n; j++){
        if (vis[j]) continue;

        vis[j] = true;
        permutation.push_back(arr[j]);
        permutationSearch(arr,vis,permutation,permutations);

        vis[j] = false;
        permutation.pop_back();
    }

    return;
}

int main() {

    /* Fast Input-Output */
    ios::sync_with_stdio(0);
    cin.tie(0);

    /* File Input-Output */
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    vector<int> arr = {1,2,3,4,5};

    vector<vector<int>> subsets, permutations;
    vector<int> subset, permutation;

    subsetSearch(0,arr,subset,subsets);

    vector<bool> vis(arr.size(),false);
    permutationSearch(arr,vis,permutation,permutations);

    int i = 1;
    for (auto array : subsets){
        cout << i++ << ") ";
        for (auto num : array){
            cout << num << " ";
        }
        cout << endl;
    }

    i = 1;
    for (auto array : permutations){
        cout << i++ << ") ";
        for (auto num : array){
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
