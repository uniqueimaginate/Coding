def solution(numbers, hand):
    l_touch = [1, 4, 7, '*']
    r_touch = [3, 6, 9, '#']
    m_touch = [2, 5, 8, 0]
    stage_dict = {1:0, 2:0, 3:0, 4:1, 5:1, 6:1, 7:2, 8:2, 9:2, '*':3, 0:3, '#':3}

    
    l_pos = '*'
    r_pos = '#'
    answer = ''

    for number in numbers:
        if number in l_touch:
            answer += 'L'
            l_pos = number
        elif number in r_touch:
            answer += 'R'
            r_pos = number
        else:
            l_stage = stage_dict[l_pos]
            r_stage = stage_dict[r_pos]
            stage = stage_dict[number]
            
            vl_dist = abs(l_stage - stage)
            vr_dist = abs(r_stage - stage)
            hl_dist = 1 if l_pos in l_touch else 0
            hr_dist = 1 if r_pos in r_touch else 0
            l_dist_num = vl_dist + hl_dist
            r_dist_num = vr_dist + hr_dist
            
            if l_dist_num > r_dist_num:
                answer += 'R'
                r_pos = number
            elif l_dist_num < r_dist_num:
                answer += 'L'
                l_pos = number
            else:
                if hand == 'left':
                    answer += 'L'
                    l_pos = number
                else:
                    answer += 'R'
                    r_pos = number
    return answer