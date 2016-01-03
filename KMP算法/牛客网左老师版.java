 /*
 ����Ŀ��
���������ַ���str��match�����ȷֱ�ΪN��M��ʵ��һ���㷨������ַ���str�к����ִ�match���򷵻�match��str�еĿ�ʼλ�ã��������򷵻�-1��
��������
str=��acbc����match=��bc��������2��
str=��acbc����match=��bcc��������-1��
��Ҫ��
���match�ĳ��ȴ���str����(M>N)��str��Ȼ���Ậ��match����ֱ�ӷ���-1�������N>=M��Ҫ���㷨���Ӷ�O(N)��
 */
 
 public int getIndexOf(String s, String m) {
        if (s == null || m == null || m.length() < 1 || s.length() < m.length()) {
        return -1;
        }
        char[] ss = s.toCharArray();
        char[] ms = m.toCharArray();
        int si = 0;
        int mi = 0;
        int[] next = getNextArray(ms);
        while (si < ss.length && mi < ms.length) {
        if (ss[si] == ms[mi]) {
            si++;
            mi++;
        } else if (next[mi] == -1) {
            si++;
        } else {
            mi = next[mi];
        }
        }
        return mi == ms.length ? si - mi : -1;
    }


    public int[] getNextArray(char[] ms) {
        if (ms.length == 1) {
            return new int[] { -1 };
        }
        int[] next = new int[ms.length];
        next[0] = -1;
        next[1] = 0;
        int pos = 2;
        int cn = 0;
        while (pos < next.length) {
            if (ms[pos - 1] == ms[cn]) {
                next[pos++] = ++cn;
            } else if (cn > 0) {
                cn = next[cn];
            } else {
                next[pos++] = 0;
            }
        }
        return next;
    }