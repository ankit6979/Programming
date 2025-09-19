class Solution {
    public:
        int minDominoRotationsBottomsHelper(vector<int>& tops, vector<int>& bottoms, int face_value, int rotation) {
            for(int dice = 1; dice < tops.size(); ++dice) {
                if(bottoms[dice] != face_value) {
                    if(tops[dice] == face_value) {
                        rotation += 1;
                    }
                    else{
                        return INT_MAX;
                    }
                }
            }
            return rotation;
        }
        int minDominoRotationsTopsHelper(vector<int>& tops, vector<int>& bottoms, int face_value, int rotation) {
            for(int dice = 1; dice < tops.size(); ++dice) {
                if(tops[dice] != face_value) {
                    if(bottoms[dice] == face_value) {
                        rotation += 1;
                    }
                    else{
                        return INT_MAX;
                    }
                }
            }
            return rotation;
        }
        int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
            int min_rotation = INT_MAX;
    
            int top_faces, bottom_faces;
            top_faces = minDominoRotationsTopsHelper(tops, bottoms, tops[0], 0);
            if(top_faces != INT_MAX) {
                bottom_faces = minDominoRotationsBottomsHelper(tops, bottoms, tops[0], 1);
                min_rotation = min({min_rotation, top_faces, bottom_faces});
            }
    
            top_faces = minDominoRotationsTopsHelper(tops, bottoms, bottoms[0], 1);
            if(top_faces != INT_MAX) {
                bottom_faces = minDominoRotationsBottomsHelper(tops, bottoms, bottoms[0], 0);
                min_rotation = min({min_rotation, top_faces, bottom_faces});
            }
    
            if(min_rotation == INT_MAX) return -1;
            return min_rotation;
        }
    };