def searchMatrix(matrix:list,target:int)->bool:
    # Dimensions of the matrix
    row=len(matrix)
    col=len(matrix[0]) if len(matrix)>0 else 0
    # In case of empty matrix
    if col==0:
        return False
    # Row limits to iterate the row
    row_low,row_high=0,row
    # the row and column position of the target, if found.
    target_row,target_col=-1,-1
    while row_low<row_high:
        mid= row_low+(row_high-row_low)//2
        # If the mid row contains the target
        if target>=matrix[mid][0] and target<=matrix[mid][col-1]:
            target_row=mid
            break
        # if the target might be after the mid row
        elif target>matrix[mid][col-1]:
            row_low=mid+1
        else:
            row_high=mid-1
    # if no row contains the target element 
    if target_row==-1:
        return False
    col_low,col_high=0,col
    while col_low<col_high:
        mid=col_low+(col_high-col_low)//2
        if target==matrix[target_row][mid]:
            return True
        elif target>matrix[target_row][mid]:
            col_low=mid+1
        else:
            col_high=mid-1
    # If the element was not found in the selected row.
    return False

