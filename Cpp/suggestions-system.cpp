class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
    {
        sort(products.begin(), products.end()); //sort products to get elements in lexicographical order
        vector<vector<string>> res;
        
        string cur = "";
        for(auto it: searchWord) //cover searchWord letter by letter
        {
            vector<string> suggested;
            cur += it;
            int j=0;
            for(auto product:products) //find cur string in products
            {
                if(j==3) break; //when we suggested 3 products
                
                if(product.substr(0, cur.size()) == cur) //matching cur with product substring
                {
                    suggested.push_back(product); //if match push it in suggested
                    j++;
                }
                    
            }
            res.push_back(suggested); //push vector for cur in res
        }
        return res;
    }
};