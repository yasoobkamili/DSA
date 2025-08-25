
def binSearch(cards,key,low,high):
    if low > high:
        print("not found")
        return
    mid = (low + high )//2
    if cards[mid] == key :
        print("found at",mid+1)
    elif cards[mid]< key:
        binSearch(cards,key,mid+1,high)
    else:
        binSearch(cards,key,low,mid-1)


cards1 = [2,5,12,25,35,40,45,78,98]
cards = [1,1,2]
low,high = 0,len(cards)-1        
binSearch(cards,2,low,high)