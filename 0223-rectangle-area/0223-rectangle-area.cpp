class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        long long area1 = (long long)(ax2 - ax1) * (ay2 - ay1);
        long long area2 = (long long)(bx2 - bx1) * (by2 - by1);

        long long overlapWidth = min(ax2, bx2) - max(ax1, bx1);
        long long overlapHeight = min(ay2, by2) - max(ay1, by1);

        long long overlapArea = 0;
        if (overlapWidth > 0 && overlapHeight > 0) {
            overlapArea = overlapWidth * overlapHeight;
        }

        return (int)(area1 + area2 - overlapArea);
    }
};