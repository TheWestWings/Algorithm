l = input().split(",")

ans = 0
for i in range(len(l)):
    if(l[i] == "..."):
        ans += int(l[i + 1]) - int(l[i - 1]) - 1

print(ans)