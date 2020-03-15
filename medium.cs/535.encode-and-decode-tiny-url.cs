/*
 * @lc app=leetcode id=535 lang=csharp
 *
 * [535] Encode and Decode TinyURL
 */

// @lc code=start
public class Codec
{
    private List<string> map = new List<string>();
    // Encodes a URL to a shortened URL
    public string encode(string longUrl)
    {
        int v = map.Count;
        map.Insert(v, longUrl);
        string url = "";
        do
        {
            int m = v % 62;
            if (m < 10)
            {
                url += (char)('0' + m);
            }
            else if (m < 36)
            {
                url += (char)('a' + m - 10);
            }
            else
            {
                url += (char)('A' + m - 36);
            }
            v /= 62;
        } while (v > 0);
        return url;
    }

    // Decodes a shortened URL to its original URL.
    public string decode(string shortUrl)
    {
        int v = 0;
        foreach (char c in shortUrl)
        {
            v *= 62;
            if (c >= '0' && c <= '9')
            {
                v += c - '0';
            }
            else if (c >= 'a' && c <= 'z')
            {
                v += c - 'a' + 10;
            }
            else
            {
                v += c - 'A' + 36;
            }
        }
        return map[v];
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(url));
// @lc code=end

