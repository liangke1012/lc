
import re

def validate_strict_email(email):
    """
    严格邮箱验证函数
    规则：
    1. 只允许字母数字和._-字符
    2. 有且仅有一个@
    3. 不能以非字母数字开头或结尾
    4. 禁止出现.@或@.
    """
    # 基础正则：字母数字开头结尾，中间允许._-
    pattern = r'^[a-zA-Z0-9][a-zA-Z0-9._-]*[a-zA-Z0-9]@[a-zA-Z0-9][a-zA-Z0-9._-]*[a-zA-Z0-9]$'
    
    # 检查基础格式
    if not re.fullmatch(pattern, email):
        return False
    
    # 检查特殊禁止模式
    if '.@' in email or '@.' in email:
        return False
    
    # 确保只有一个@
    return email.count('@') == 1

# 测试用例
test_cases = [
    ("valid.email@example.com", True),
    ("user_name-123@domain.com", True),
    ("invalid@.com", False),
    ("@invalid.com", False),
    ("valid@domain..com", False),
    ("-invalid@domain.com", False)
]

for email, expected in test_cases:
    result = validate_strict_email(email)
    print(f"测试 {email}: {'通过' if result == expected else '失败'}")
