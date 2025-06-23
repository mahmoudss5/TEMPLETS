  for (int i = 1; i < s.size(); ++i) {  // here is the kmp algorithm ( يارب افهمه )
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j]) {
                j = pi[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            pi[i] = j;

        }
