using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class UnityAttributeTest : MonoBehaviour
{
    #region Unity Default Attributes

    //1.serializedField : 일반적으로 인스펙터에서 가려져야 하는 private 또는 protected 변수를 inspector에서 접근 가능하도록 하는 기능
    [SerializeField]
    private int privateIntVar;

    //2. TextArea : 문자열 입력란을 기본 1줄이 아니라 TextArea(MinRow,MaxRow) 형태로 입력이 가능하도록 표시
    [TextArea(2,5)]
    public string text;

    //3. Header : Inspector에서 중간에 특정 라벨을 끼워넣음
    [Header("헤더 테스트")]
    public int otherIntVar;

    //4. Space : Inspector에서 입력칸 사이의 간격을 띄움
    [Space(100)]
    public int floatVar;

    //5. Range : Inspector에서 int 또는 float 변수에 최대/최소값을 제한하며 , 슬라이더바로 값을 바꿀수 있게 해줌.
    [Range(0, 1)]
    public float rangedFloat;

    [Range(-5, 5)]
    public int rangedInt;

    //6. Tooltip : Inspector에서 해당 변수에 마우스를 올릴 경우 설명을 띄워준다.
    [Tooltip("이것은 툴팁입니다.")]
    public string otherText;

    //7. HideInInspector : 외부 객체에서 접근은 가능하나 Inspector에서 값을 가려야 할 때 사용.
    //주의사항 : Debug 모드에서도 값을 볼수 없다.
    [HideInInspector]
    public int publicIntVar;

    //internal 접근지정자 : 같은 어셈블리(네임스페이스) 내에서만 접근 가능한 접근지정자.
    //다른 객체에서 접근가능 , Inspector에서는 확인 불가하나 Debug mode에서 확인 가능하다.
    internal int interanalIntvar;

    #endregion
    void Start()
    {
        
    }
    void Update()
    {
        
    }
}