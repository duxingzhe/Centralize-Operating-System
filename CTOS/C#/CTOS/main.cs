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
    public partial class main : Form
    {
        string sql = @"SELECT * FROM Loop"; 
        SqlConnection conn = new SqlConnection(login.strconn);
        SqlCommand cmd;
       
        public main()
        {
            InitializeComponent();
        }

        private void quit_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void add_Click(object sender, EventArgs e)
        {
            add addwin = new add();
            addwin.Show();
            DataUpdate();
        }

        private void main_Load(object sender, EventArgs e)
        {
            this.loopTableAdapter.Fill(this.loop._Loop);
        }

        private void show_Click(object sender, EventArgs e)
        {
            int i=0;
            conn.Open();
            cmd = new SqlCommand(sql,conn);
            SqlDataReader rdr = cmd.ExecuteReader();
            while (rdr.Read())
            { 
                MessageBox.Show("姓名：" + rdr[1].ToString().PadLeft(21)+"\n性别："+rdr[2].ToString().PadLeft(21)+"\n职业："+rdr[3].ToString().PadLeft(21)+
                     "\n电话：" + rdr[4].ToString().PadLeft(21) + "\n住址：" + rdr[5].ToString().PadLeft(21) + "\n婚姻状况：" + rdr[6].ToString().PadLeft(21) + 
                     "\n薪金：" + rdr[7].ToString().PadLeft(21) + "\n年龄：" + rdr[8].ToString().PadLeft(21));
                i++;
                if(i==1)
                {
                    MessageBox.Show("I am the Vigilante. I am a hacker. I know you are checking my information.", "Error",
                        MessageBoxButtons.OK,MessageBoxIcon.Error);
                }
            }
            rdr.Close();
        }

        public void update_Click(object sender, EventArgs e)
        {
            DataUpdate();
        }
        private void DataUpdate()
        {
            SqlDataAdapter dataAdapter = new SqlDataAdapter(sql, conn);

            DataSet dataSet = new DataSet("Loop");

            // 填充数据集
            dataAdapter.Fill(dataSet, "Loop");

            // 指定 DataGridView 的数据源
            dataGridView1.DataSource = dataSet.Tables["Loop"];
        }

        private void review_Click(object sender, EventArgs e)
        {
            review reviewwin = new review();
            reviewwin.Show();
            DataUpdate();
        }

        private void delete_Click(object sender, EventArgs e)
        {
            delete deletewin = new delete();
            DataUpdate();
        }
    }
}
