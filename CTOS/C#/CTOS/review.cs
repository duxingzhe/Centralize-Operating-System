using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CTOS
{
    public partial class review : Form
    {
        string sql = @"SELECT count(*) FROM Loop";
        SqlConnection conn = new SqlConnection(login.strconn);
        SqlCommand cmd;
        public review()
        {
            InitializeComponent();
        }

        private void review_Load(object sender, EventArgs e)
        {
            int i = 0;
            SqlDataAdapter dataAdapter = new SqlDataAdapter(sql, conn);
            DataSet dataSet = new DataSet("Loop");
            conn.Open();
            cmd = new SqlCommand(sql, conn);
            for(i=1;i<=Int32.Parse(cmd.ExecuteScalar().ToString());i++)
            {
                comboBox1.Items.Add(i);
            }
            DataRow datarow = dataSet.Tables[0].NewRow();
            datarow[0] = "0 ";
            datarow[1] = "请选择 ";
            dataSet.Tables[0].Rows.InsertAt(datarow, 0);
            comboBox2.DataSource = dataSet;//也可以用ds，此处就是ds.Tables[0];
            comboBox2.DisplayMember = "Loop"; //绑定显示成员的名字
            comboBox2.ValueMember = "id";//绑定combox显示成员的值
            comboBox2.SelectedValue = "0";//让combox固定显示某个成员名字。
        }

        private void close_Click(object sender, EventArgs e)
        {
            this.Close();
        }

    }
}
