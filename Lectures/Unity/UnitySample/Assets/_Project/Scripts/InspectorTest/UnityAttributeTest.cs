using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class UnityAttributeTest : MonoBehaviour
{
    #region Unity Default Attributes

    //1.serializedField : �Ϲ������� �ν����Ϳ��� �������� �ϴ� private �Ǵ� protected ������ inspector���� ���� �����ϵ��� �ϴ� ���
    [SerializeField]
    private int privateIntVar;

    //2. TextArea : ���ڿ� �Է¶��� �⺻ 1���� �ƴ϶� TextArea(MinRow,MaxRow) ���·� �Է��� �����ϵ��� ǥ��
    [TextArea(2,5)]
    public string text;

    //3. Header : Inspector���� �߰��� Ư�� ���� ��������
    [Header("��� �׽�Ʈ")]
    public int otherIntVar;

    //4. Space : Inspector���� �Է�ĭ ������ ������ ���
    [Space(100)]
    public int floatVar;

    //5. Range : Inspector���� int �Ǵ� float ������ �ִ�/�ּҰ��� �����ϸ� , �����̴��ٷ� ���� �ٲܼ� �ְ� ����.
    [Range(0, 1)]
    public float rangedFloat;

    [Range(-5, 5)]
    public int rangedInt;

    //6. Tooltip : Inspector���� �ش� ������ ���콺�� �ø� ��� ������ ����ش�.
    [Tooltip("�̰��� �����Դϴ�.")]
    public string otherText;

    //7. HideInInspector : �ܺ� ��ü���� ������ �����ϳ� Inspector���� ���� ������ �� �� ���.
    //���ǻ��� : Debug ��忡���� ���� ���� ����.
    [HideInInspector]
    public int publicIntVar;

    //internal ���������� : ���� �����(���ӽ����̽�) �������� ���� ������ ����������.
    //�ٸ� ��ü���� ���ٰ��� , Inspector������ Ȯ�� �Ұ��ϳ� Debug mode���� Ȯ�� �����ϴ�.
    internal int interanalIntvar;

    #endregion
    void Start()
    {
        
    }
    void Update()
    {
        
    }
}