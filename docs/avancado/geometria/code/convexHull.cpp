vector<point> convex_hull(const vector<point> &points)
{
    vector<point> P(points);
    sort(P.begin(), P.end());
    vector<point> L, U;
    for(auto p: P){
        while(L.size()>=2 and ccw(L[L.size()-2], L.back(), p)!=1)
            L.pop_back();
        L.push_back(p);
    }
    reverse(P.begin(), P.end());
    for(auto p: P){
        while(U.size()>=2 and ccw(U[U.size()-2], U.back(), p)!=1)
            U.pop_back();
        U.push_back(p);
    }
    L.pop_back();
    L.insert(L.end(), U.begin(), U.end()-1);
    return L;
}
