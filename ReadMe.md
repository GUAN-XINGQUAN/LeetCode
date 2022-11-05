# LeetCode Summary

# Table of Contents

- [Binary Search](#binary_search)
- [SQL Relevance](#sql)

## <a name='binary_search'>Binary Search</a>

**Generic Notes**

The template for *binary search*:

```cpp
// Fill the spot marked with ...
int binarySearch(int[] nums, int target) {
    int left = 0, right = ...;  // initial condition

    while(...) {  // termination condition
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            ...  // proceed condition
        } else if (nums[mid] < target) {
            left = ...  // proceed condition
        } else if (nums[mid] > target) {
            right = ...  // proceed condition
        }
    }
    return ...; // return variable
}
```

| Scenario | Initial Condition | Termination Condition | Proceed Condition                            | Return Variable | Example Problems | Scenario                               |
|:--------:|:-----------------:|:---------------------:|:--------------------------------------------:|:---------------:|:----------------:|:--------------------------------------:|
| 1        | [0, len-1]        | left<=right           | return mid;<br/>left=mid+1;<br/>right=mid-1; | return -1       | 704              | Find a single number in a sorted array |
|          |                   |                       |                                              |                 |                  |                                        |

**Problems:**

- [35. Search Insert Position](/Binary%20Search/35.%20Search%20Insert%20Position.cpp)

- [69. Sqrt(x)](/Binary%20Search/69.%20Sqrt(x).cpp)

- [367. Valid Perfect Square](/Binary%20Search/367.%20Valid%20Perfect%20Square.cpp)

- [374. Guess Number Higher or Lower](/Binary%20Search/374.%20Guess%20Number%20Higher%20or%20Lower.cpp)

- [704. Binary Search](/Binary%20Search/704%20Binary%20Search.cpp)

- [744. Find Smallest Letter Greater Than Target](/Binary%20Search/744.%20Find%20Smallest%20Letter%20Greater%20Than%20Target.cpp)

- [852. Peak Index in a Mountain Array](/Binary%20Search/852.%20Peak%20Index%20in%20a%20Mountain%20Array.cpp)

- [1385. Find the Distance Value Between Two Arrays](/Binary%20Search/1385.%20Find%20the%20Distance%20Value%20Between%20Two%20Arrays.cpp)

## <a name='sql'>SQL Relevance</a>

**Generic Notes**:

Order of Statements When Writing a Query:

<SELECT>  <FROM>  <JOINs> <WHERE> <GROUP BY> <HAVING> <ORDER BY> <LIMIT> <OFFSET>

Order of Execution:

<FROM> <ON> <JOIN> <WHERE> <GROUP BY> <HAVING> <SELECT> <DISTINCT> <ORDER BY>

**Problems:****

- [175. Combine Two Tables](/SQL%20Practice/175.%20Combine%20Two%20Tables.sql)

- [176. Second Highest Salary](/SQL%20Practice/176.%20Second%20Highest%20Salary.sql)

- [182. Duplicate Emails](/SQL%20Practice/182.%20Duplicate%20Emails.sql)

- [183. Customers Who Never Order](/SQL%20Practice/183.%20Customers%20Who%20Never%20Order.sql)

- [196. Delete Duplicate Emails](/SQL%20Practice/196.%20Delete%20Duplicate%20Emails.sql)

- [197. Rising Temperature](/SQL%20Practice/197.%20Rising%20Temperature.sql)

- [511. Game Play Analysis I](/SQL%20Practice/511.%20Game%20Play%20Analysis%20I.sql)

- [584. Find Customer Referee](/SQL%20Practice/584.%20Find%20Customer%20Referee.sql)

- [586. Customer Placing the Largest Number of Orders](/SQL%20Practice/586.%20Customer%20Placing%20the%20Largest%20Number%20of%20Orders.sql)

- [595. Big Countries](/SQL%20Practice/595.%20Big%20Countries.sql)

- [607. Sales Person](/SQL%20Practice/607.%20Sales%20Person.sql)

- [608. Tree Node](/SQL%20Practice/608.%20Tree%20Node.sql)

- [627. Swap Salary](/SQL%20Practice/627.%20Swap%20Salary.sql)

- [1050. Actors and Directors Who Cooperated At Least](/SQL%20Practice/1050.%20Actors%20and%20Directors%20Who%20Cooperated%20At%20Least%20Three%20Times.sql)

- [1084. Sales Analysis III](/SQL%20Practice/1084.%20Sales%20Analysis%20III.sql)

- [1141. User Activity for the Past 30 Days I](/SQL%20Practice/1141.%20User%20Activity%20for%20the%20Past%2030%20Days%20I.sql)

- [1148. Article Views I](/SQL%20Practice/1148.%20Article%20Views%20I.sql)

- [1158. Market Analysis I](/SQL%20Practice/1158.%20Market%20Analysis%20I.sql)

- [1393. Capital GainLoss](/SQL%20Practice/1393.%20Capital%20GainLoss.sql)

- [1407. Top Travellers](/SQL%20Practice/1407.%20Top%20Travellers.sql)

- [1484. Group Sold Products By The Date](/SQL%20Practice/1484.%20Group%20Sold%20Products%20By%20The%20Date.sql)

- [1527. Patients With a Condition](/SQL%20Practice/1527.%20Patients%20With%20a%20Condition.sql)

- [1587. Bank Account Summary II](/SQL%20Practice/1587.%20Bank%20Account%20Summary%20II.sql)

- [1581. Customer Who Visited but Did Not Make Any Transactions](/SQL%20Practice/1581.%20Customer%20Who%20Visited%20but%20Did%20Not%20Make%20Any%20Transactions.sql)

- [1667. Fix Names in a Table](/SQL%20Practice/1667.%20Fix%20Names%20in%20a%20Table.sql)

- [1693. Daily Leads and Partners](/SQL%20Practice/1693.%20Daily%20Leads%20and%20Partners.sql)

- [1741. Find Total Time Spent by Each Employee](/SQL%20Practice/1741.%20Find%20Total%20Time%20Spent%20by%20Each%20Employee.sql)

- [1729. Find Followers Count](/SQL%20Practice/1729.%20Find%20Followers%20Count.sql)

- [1757. Recyclable and Low Fat Products](/SQL%20Practice/1757.%20Recyclable%20and%20Low%20Fat%20Products.sql)

- [1795. Rearrange Products Table](/SQL%20Practice/1795.%20Rearrange%20Products%20Table.sql)

- [1873. Calculate Special Bonus](/SQL%20Practice/1873.%20Calculate%20Special%20Bonus.sql)

- [1890. The Latest Login in 2020](/SQL%20Practice/1890.%20The%20Latest%20Login%20in%202020.sql)

- [1965. Employees With Missing Information](/SQL%20Practice/1965.%20Employees%20With%20Missing%20Information.sql)
