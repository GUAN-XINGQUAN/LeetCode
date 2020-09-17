class Solution:
    def trap(self, height: List[int]) -> int:
        h_array = []
        i_array = []
        vol = 0
        for _i, _h in enumerate(height):
            # First elem
            if not i_array:
                i_array.append(_i)
                h_array.append(_h)
            
            # Lower bar (left > right), add to h_array, add new idx to i_array
            elif _h < h_array[i_array[-1]]:
                h_array.append(_h)
                i_array.append(_i)
            
            # Equal bar (left == right), add to h_array, replace new i_array
            elif _h == h_array[i_array[-1]]:
                h_array.append(_h)
                i_array[-1] = _i
            
            # Higher bar (left < right), add to h_array, fill cement
            # A special case for left < right
            elif _h > h_array[i_array[-1]] and len(i_array) == 1:
                    i_array[0] = _i
                    h_array.append(_h)      
                    
            # A general case for left < right
            else:                
                # By this time, the corresponding h of i_array[-1] < h      
                _f_h_array = []
                _f_w_array = []
                _len = len(i_array)
                for _valid_idx in range(_len - 1, -1, -1):
                    _left_h_idx = i_array[_valid_idx]
                    _left_h = h_array[_left_h_idx]
                    
                    # Mark as "to be filled"
                    if _left_h < _h and _valid_idx > 0:
                        _f_w_array.append(_left_h_idx)
                        _f_h_array.append(_left_h)
                        i_array.pop(-1)
                        
                        
                    # Fill. Add _i into valid idx array. Break.
                    elif _left_h >= _h or _valid_idx == 0:                      
                        _max_h = min(_left_h, _h)
                        _f_w_array.append(_left_h_idx)
                        _f_h_array.append(_left_h)
                        for _j in range(0, len(_f_w_array) - 1):
                            _grid_h = _max_h - _f_h_array[_j]
                            _grid_w = _f_w_array[_j] - _f_w_array[_j + 1]
                            vol += _grid_h * _grid_w
                        if _left_h <= _h:
                            i_array[-1] = _i
                        else:
                            i_array.append(_i)
                        h_array.append(_h)
                        break
        return vol
                    
        
        
"""
https://leetcode.com/problems/trapping-rain-water/submissions/

The key idea of the problem is to apply 2 arrays - 1 height array, and 1 valid index array. 
You can image the procedure as "filling cement". 
If the new commer is higher than the previous bar, fill cement.  
"""   