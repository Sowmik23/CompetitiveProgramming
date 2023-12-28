// A rolling hash should work for either question. Gives you an
// array shift in constant time.Hash value of row n - the last
// element in row in should equal the hash value of row n+1 - first
// element of n+1



//### Implementation of follow-up:

// I just read the partial row from the disk.
// At any given time, Memory of one row size is utilized.
// Happy coding!

class Solution {
    int offset(int i, int j, int C) {
        return (i * C) + j;
    }

    int readFromFile(vector<vector<int>> &file, int offset) {
        int line = offset / file[0].size(), pos = offset % file[0].size();
        return file[line][pos];
    }

public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix) {
        /**
         * **Problem**:
         *
         * Follow-up-1: What if the matrix is stored on disk, and the memory is limited such that
         * you can only load at most one row of the matrix into the memory at once?
         *
         * Follow-up-2: What if the matrix is so large that you can only load up a partial row into
         * the memory at once?
         * */


        deque<int> buffer;
        const int R = matrix.size(), C = matrix[0].size();
        // reading first row from
        for (int j = 0; j < C; ++j) buffer.push_back(readFromFile(matrix, offset(0, j, C)));

        for (int i = 1; i < R; ++i) {
            // free up one space
            buffer.pop_back();
            // read first
            buffer.push_front(readFromFile(matrix, offset(i, 0, C)));
            for (int j = 1; j < C; j++) if (buffer[j] != readFromFile(matrix, offset(i, j, C))) return false;
        }

        return true;
    }
};



class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {


        int m = matrix.size();
        int n = matrix[0].size();

        unordered_map<int, set<int>> mp;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //cout<<i<<" "<<j<<"<=>"<<i-1<<" "<<j-1<<"End ";
                mp[i-j].insert(matrix[i][j]);
            }
            //cout<<endl;
        }

        for(auto& m: mp){
            if(m.second.size()>1) return false;
        }

        return true;
    }
};
