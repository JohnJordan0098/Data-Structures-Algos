class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        
        int mint = logs[0][1];
        int worker = logs[0][0];
        
        for(int i = 1; i < logs.size(); i++){
            cout << logs[i][1] << " # " << worker << endl;
            if(logs[i][1]-logs[i-1][1] > mint){
                
                mint = logs[i][1]-logs[i-1][1];
                worker = logs[i][0];
                cout << mint << " ^ " << worker << endl;
            }
            if(logs[i][1]-logs[i-1][1] == mint) worker = min(worker, logs[i][0]);
        }
        cout << mint << " @ " << worker << endl;
        return worker;
    }
};