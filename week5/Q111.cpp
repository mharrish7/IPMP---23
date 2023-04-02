class TopVotedCandidate {
    vector<int> times, lead; 
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) : times(times) {
        unordered_map<int, int> freq; 
        int pp = 0; 
        for (auto& p : persons) {
            ++freq[p]; 
            if (freq[p] >= freq[pp]) pp = p; 
            lead.push_back(pp);
        }
    }
    
    int q(int t) {
        int k = upper_bound(times.begin(), times.end(), t) - times.begin();
        return lead[k-1]; 
    }
};