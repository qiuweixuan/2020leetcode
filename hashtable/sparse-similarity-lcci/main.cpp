#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

class Solution
{
public:
    vector<string> computeSimilarities(vector<vector<int>> &docs)
    {
        stringstream ss;
        char buf[1024];
        vector<string> similarSetStr;
        vector<set<int>> docs_set(docs.size());

        for (int i = 0; i < docs.size(); i++)
        {
            auto &&words = docs[i];
            for (auto word : words)
            {
                docs_set[i].insert(word);
            }
        }

        for (int i = 0; i < docs_set.size(); i++)
        {
            auto &&lset = docs_set[i];
            for (int j = i + 1; j < docs_set.size(); j++)
            {
                auto &&rset = docs_set[j];

                set<int> lr_intersection;
                set_intersection(lset.begin(), lset.end(), rset.begin(), rset.end(), inserter(lr_intersection, lr_intersection.begin()));

                if (!lr_intersection.empty())
                {
                    set<int> lr_union;
                    set_union(lset.begin(), lset.end(), rset.begin(), rset.end(), inserter(lr_union, lr_union.begin()));
                    double union_size = lr_union.size();
                    double inter_size = lr_intersection.size();
                    double div_inter_union = inter_size / union_size;

                    sprintf(buf,"%d,%d: %.4f\0",i,j,div_inter_union);
                    string result_str(buf);
                    similarSetStr.push_back(result_str);

                }
            }
        }
        return similarSetStr;
    }
};