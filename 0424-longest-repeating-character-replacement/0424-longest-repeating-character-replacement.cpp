class Solution {
public:
    int characterReplacement(string s, int k) {

        int freq[26] = {0};

        int left = 0;
        int maxfreq = 0;
        int maxwindow = 0;

        for (int right = 0; right < s.length(); right++) {

            freq[s[right] - 'A']++;

            maxfreq = max(maxfreq, freq[s[right] - 'A']);

            int windowlength = right - left + 1;

            if (windowlength - maxfreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            windowlength = right - left + 1;

            maxwindow = max(maxwindow, windowlength);
        }

        return maxwindow;
    }
};